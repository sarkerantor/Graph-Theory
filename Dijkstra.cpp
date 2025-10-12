#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("input.txt","r",stdin);
    int node,edge,x,y,w,src;
    cin>>node>>edge;
    vector<vector<pair<int,int>>>v(node+1);
    while(edge--){
      cin>>x>>y>>w;
      v[x].push_back({y,w});
      v[y].push_back({x,w});
    }
    vector<int>dist(node+1,INT_MAX);
    cin>>src;
    dist[src]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,src});
    while(!pq.empty()){
      int dis=pq.top().first;
      int node=pq.top().second;
      pq.pop();
      for(auto it:v[node]){
         int adjnode=it.first;
         int nodewt=it.second;
         if(dist[adjnode] > dis+nodewt){
            dist[adjnode]=dis+nodewt;
            pq.push({dist[adjnode],adjnode});
         }
      }
    }
    for(int i=0;i<=node;i++)cout<<dist[i]<<" ";
    return 0;
}
/*
Input:
6 8
0 1 4
0 2 4
1 2 2
2 3 3
2 4 1
2 5 6
3 5 2
4 5 3
0
*/
