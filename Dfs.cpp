#include<bits/stdc++.h>
using namespace std;
vector<int>v[10001];
int vis[10001];
void dfs(int node){
    vis[node]=1;
    cout<<node<<" ";
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
    dfs(1);
    return 0;
}
/*
Input:
6 5
1 2
2 3
2 4
4 5
4 6
*/
