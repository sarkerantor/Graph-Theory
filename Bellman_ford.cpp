#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("input.txt","r",stdin);
    int node,edge,x,y,w,src;
    cin>>node>>edge;
    vector<vector<int>>graph;
    while(edge--){
        vector<int>a(3);
        //u,v,wt
        cin>>a[0]>>a[1]>>a[2];
        graph.push_back({a});
    }
    cin>>src;
    vector<int>dist(node+1,INT_MAX);
    dist[src]=0;
    for(int i=1;i<node;i++){
        for(auto it:graph){
            if(dist[it[0]] != INT_MAX && dist[it[0]]+it[2] < dist[it[1]]){
                dist[it[1]]=dist[it[0]]+it[2];
            }
        }
    }
    bool hasNegativeCycle=false;
    for(auto it:graph){
        if(dist[it[0]] != INT_MAX && dist[it[0]]+it[2] < dist[it[1]]){
            hasNegativeCycle=true;
            break;
        }
    }
    if(hasNegativeCycle){
        cout<<"Graph has a negative cycle"<<endl;
    }
    else{
        for(int i=0;i<=node;i++)cout<<dist[i]<<" ";
    }
    return 0;
}
