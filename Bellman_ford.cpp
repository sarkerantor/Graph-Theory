#include<bits/stdc++.h>
using namespace std;
const int inf=1e7;
int main(){
    freopen("input.txt","r",stdin);
    int node,m,x,y,w;
    cin>>node>>m;
    vector<int>dist(node,inf);
    vector<vector<int>>edge;
    while(m--){
        cin>>x>>y>>w;
        edge.push_back({x,y,w});
    }
    int source;
    cin>>source;
    dist[source]=0;
    for(int i=0;i<node-1;i++){
        for(auto it:edge){
            int u=it[0],v=it[1],w=it[2];
            dist[v]=min(dist[v],w+dist[u]);
        }
    }
    for(int i=0;i<node;i++)cout<<dist[i]<<" ";
    return 0;
}
/*
Input:
5 8
1 2 3
3 2 5
1 3 2
3 1 1
1 4 2
0 2 4
4 3 -3
0 1 -1
0
*/
