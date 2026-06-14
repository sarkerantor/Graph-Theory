#include<bits/stdc++.h>
using namespace std;
const int N=200005;
vector<int>adj[N];
int up[N][20];
int depth[N];
void dfs(int node,int par){
    up[node][0]=par;
    for(int i=1;i<20;i++){
        up[node][i]=up[up[node][i-1]][i-1];
    }
    for(int child:adj[node]){
        if(child==par)continue;
        depth[child]=depth[node]+1;
        dfs(child,node);
    }
}
int lca(int u,int v){
    if(depth[u]<depth[v])swap(u,v);
    int dif=depth[u]-depth[v];
    for(int j=19;j>=0;j--){
        if((dif>>j)&1){
            u=up[u][j];
        }
    }
    if(u==v)return u;
    for(int i=19;i>=0;i--){
        if(up[u][i]!=up[v][i]){
            u=up[u][i];
            v=up[v][i];
        }
    }
    return up[u][0];
}
int main(){
    int node,edge;
    cin>>node>>edge;
    while(edge--){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int root=1;
    depth[root]=0;
    dfs(root,root);
    int q;
    cin>>q;
    while(q--){
        int u,v;
        cin>>u>>v;
        cout<<lca(u,v)<<endl;
    }
    return 0;
}
