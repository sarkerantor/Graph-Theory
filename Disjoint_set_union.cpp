#include<bits/stdc++.h>
using namespace std;
const int n=1e5+6;  
vector<int>parent(n);
vector<int>sz(n);
void make_set(int v){
    parent[v]=v;
    sz[v]=1;
}
int find_set(int v){
    if(v==parent[v])return v;
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
    //freopen("input.txt","r",stdin);
    for(int i=0;i<n;i++){
        make_set(i);
    }
    int n,m;
    cin>>n>>m;
    vector<vector<int>>edge;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        edge.push_back({u,v});
    }
    bool cycle=false;
    for(auto it:edge){
        int u=it[0];
        int v=it[1];
        int x=find_set(u);
        int y=find_set(v);
        if(x==y){
            cycle=true;
        }
        else union_set(u,v);
    }
    if(cycle)cout<<"Cycle"<<endl;
    else cout<<"Not cycle"<<endl;
    return 0;
}
