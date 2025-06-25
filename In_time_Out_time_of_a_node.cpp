#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
vector<int>v[10000];
int vis[10000],in[10000],out[10000];
int timer=1;
void dfs(int node){
    vis[node]=1;
    in[node]=timer++;
    for(int child:v[node]){
        if(!vis[child])dfs(child);
    }
    out[node]=timer++;
}
int main(){
    freopen("input.txt","r",stdin);
    int node,edge,x,y;
    cin>>node>>edge;
    while(edge--){
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1);
    for(int i=1;i<=node;i++)cout<<"Intime : "<<in[i]<<" Outtime : "<<out[i]<<endl;
    return 0;
}
/*
Input:
7 6
1 2
2 4
2 5
1 3
3 6
3 7
*/
