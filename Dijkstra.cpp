#include<bits/stdc++.h>
using namespace std;
const int inf=1e7;
int main(){
    freopen("input.txt","r",stdin);
    int node,edge,x,y,w;
    cin>>node>>edge;
    vector<int>dist(node+1,inf);
    vector<vector<pair<int,int>>>graph(node+1);
    while(edge--){
        cin>>x>>y>>w;
        graph[x].push_back({y,w});
        graph[y].push_back({x,w});
    }
    int source;
    cin>>source;
    dist[source]=0;
    set<pair<int,int>>s;
    //{weight,vertex}
    s.insert({0,source});
    while (!s.empty())
    {
        auto x=*(s.begin());
        s.erase(x);
        for(auto it:graph[x.second]){
            if(dist[it.first]>dist[x.second]+it.second){
                s.erase({dist[it.first],it.first});
                dist[it.first]=dist[x.second]+it.second;
                s.insert({dist[it.first],it.first});
            }
        }
    }
    cout<<"The minimum distance from "<<source <<" to other vertex : ";
    for(int i=1;i<=node;i++)cout<<dist[i]<<" ";
    return 0;
}
/*
Input:
5 6
1 2 5
1 5 1
1 4 9
2 3 2
3 4 6
4 5 2
1
*/
