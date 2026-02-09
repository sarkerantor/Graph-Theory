#include<bits/stdc++.h>
using namespace std;
const int N=200005;
vector<int>v[N];
vector<int>euler;
int depth[N],first[N],vis[N];
int sparse[2*N][20];
void dfs(int node,int d){
    vis[node]=1;
    depth[node]=d;
    first[node]=euler.size();
    euler.push_back(node);
    for(int child:v[node]){
        if(!vis[child]){
            dfs(child,d+1);
            euler.push_back(node);
        }
    }
}
void build(){
    int n=euler.size();
    for(int i=0;i<n;i++)sparse[i][0]=euler[i];
    for(int i=1;i<20;i++){
        for(int j=0;j+(1<<i)<=n;j++){
            int x=sparse[j][i-1];
            int y=sparse[j+(1<<(i-1))][i-1];
            sparse[j][i]=(depth[x]<depth[y]?x:y);
        }
    }
}
int query(int l,int r){
    if(l>r)swap(l,r);
    int len=r-l+1;
    int j=log2(len);
    int x=sparse[l][j];
    int y=sparse[r-(1<<j)+1][j];
    return (depth[x]<depth[y]?x:y);
}
int lca(int u,int v){
    return query(first[u],first[v]);
}
int main(){
    //freopen("input.txt","r",stdin);
    int n,q,a;
    cin>>n>>q;
    for(int i=2;i<=n;i++){
        cin>>a;
        v[a].push_back(i);
        v[i].push_back(a);
    }
    dfs(1,0);
    build();
    while(q--){
        int u,v;
        cin>>u>>v;
        cout<<lca(u,v)<<endl;
    }
    return 0;
}
