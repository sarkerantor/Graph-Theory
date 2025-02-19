#include <bits/stdc++.h>
using namespace std;
vector<int>v[100001];
int vis[100001];
int mxnode,mx=0;
void dfs(int node,int mxv){
    vis[node]=1;
    if(mxv>mx){
        mx=mxv;
        mxnode=node;
    }
    for(int child:v[node]){
        if(!vis[child])dfs(child,mxv+1);
    }
}
int main() 
{
    int node,edge,x,y;
    cin>>node>>edge;
    while(edge--){
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1,0);
    mx=-1;
    memset(vis,0,sizeof(vis));
    dfs(mxnode,0);
    cout<<mx<<endl;
    return 0;
}
/*
Input:
9 8
1 2
1 3
2 4
2 5
4 8
3 6
3 7
7 9
*/
