#include<bits/stdc++.h>
using namespace std;
const int n=1e5;
vector<int>parent(n),sz(n);
void make_set(int v){
    parent[v]=v;
    sz[v]=1;
}
int find_set(int v){
    if(parent[v]==v)return v;
    else return parent[v]=find_set(parent[v]);
}
void union_set(int a,int b){
    a=find_set(a);
    b=find_set(b);
    if(a!=b){
        if(sz[a]<sz[b])swap(a,b);
        parent[b]=a;
        sz[a]+=sz[b];
    }
}
int main(){
    freopen("input.txt","r",stdin);
    for(int i=1;i<=n;i++){
        make_set(i);
    }
    int node,edge;
    cin>>node>>edge;
    vector<vector<int>>graph;
    while(edge--){
        int u,v,w;
        cin>>u>>v>>w;
        graph.push_back({w,u,v});
    }
    sort(graph.begin(),graph.end());
    int cost=0;
    for(auto it:graph){
        int w=it[0],u=it[1],v=it[2];
        int x=find_set(u);
        int y=find_set(v);
        if(x==y)continue;
        else{
            cout<<u<<" "<<v<<endl;
            cost+=w;
            union_set(u,v);
        }
    }
    cout<<cost;
    return 0;
}
/*
Input:
8 9
1 2 5
2 3 6
4 3 2
1 4 9
3 5 5
5 6 10
6 7 7
7 8 1
8 5 1
*/
