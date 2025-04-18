#include<bits/stdc++.h>
using namespace std;
int node,edge,cost=0,inf=1e9;
const int n=1e5;
vector<vector<int>>g[n];
vector<bool>vis(n);
vector<int>dist(n),parent(n);
void prime_mst(int src){
    for(int i=0;i<node;i++)dist[i]=inf;
    set<vector<int>>s;
    dist[src]=0;
    s.insert({0,src});
    //{wt,vertex}
    while(!s.empty()){
        auto x=*(s.begin());
        s.erase(x);
        vis[x[1]]=true;
        int u=x[1];
        int v=parent[x[1]];
        int w=x[0];
        cout<<u<<" "<<v<<" "<<w<<endl;
        cost+=w;
        for(auto it:g[x[1]]){
            if(vis[it[0]])continue;
            if(dist[it[0]]>it[1]){
                s.erase({dist[it[0]],it[0]});
                dist[it[0]]=it[1];
                s.insert({dist[it[0]],it[0]});
                parent[it[0]]=x[1];
            }
        }
    }
}
int main(){
    freopen("input.txt","r",stdin);
    cin>>node>>edge;
    while(edge--){
        int u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    prime_mst(0);
    cout<<cost;
    return 0;
}
/*
Input:
4 5
0 1 10
1 2 15
0 2 5
3 1 2
3 2 40
*/
