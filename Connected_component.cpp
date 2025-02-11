#include<bits/stdc++.h>
using namespace std;
vector<int>v[10001];
int vis[10001];
void dfs(int node){
    vis[node]=1;
    for(int i:v[node]){
        if(!vis[i])dfs(i);
    }
}
int main(){
    freopen("input.txt","r",stdin);
    int node,edge,x,y;
    cin>>node>>edge;
    while (edge--)
    {
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    int count=0;
    for(int i=1;i<=node;i++){
        if(!vis[i]){
            count++;
            dfs(i);
        }
    }
    cout<<count;
    return 0;
}
/*
Input:
10 7
1 2
1 3
3 4
3 5
6 7
8 9
8 10
*/
