#include<bits/stdc++.h>
using namespace std;
vector<int>v[1000];
int vis[1000],in[1000],low[1000];
int timer;
void dfs(int node,int par){
    vis[node]=1;
    in[node]=timer;
    low[node]=timer;
    timer++;
    for(int child:v[node]){
        if(child==par)continue;
        if(vis[child]==1)low[node]=min(low[node],in[child]);
        else{
            dfs(child,node);
            if(low[child]>in[node])cout<<node<<"->"<<child<<endl;
            low[node]=min(low[node],low[child]);
        }
    }
}
int main(){
    //freopen("input.txt","r",stdin);
    int node,edge,a,b;
    cin>>node>>edge;
    while(edge--){
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1,-1);
    return 0;
}
/*
Input:
4 4
1 2
2 3
2 4
3 4
*/
