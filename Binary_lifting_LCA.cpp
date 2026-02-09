#include<bits/stdc++.h>
using namespace std;
const int N=200005;
vector<int>v[N];
int vis[N];
int lca[N][20];
void dfs(int node,int par){
    lca[node][0]=par;
    vis[node]=1;
    for(int child:v[node]){
        if(!vis[child])dfs(child,node);
    }
}
int kthParent(int u,int k){
    for(int i=0;i<20;i++){
        if(k&(1<<i)){
            u=lca[u][i];
            if(u==-1)return u;
        }
    }
    return u;
}
int main(){
    //freopen("input.txt","r",stdin);
    int n,a,q;
    cin>>n>>q;
    for(int i=2;i<=n;i++){
        cin>>a;
        v[a].push_back(i);
        v[i].push_back(a);
    }
    memset(lca,-1,sizeof(lca));
    dfs(1,-1);
    for(int j=1;j<20;j++){
        for(int i=1;i<=n;i++){
            if(lca[i][j-1]!=-1){
                int par=lca[i][j-1];
                lca[i][j]=lca[par][j-1];
            }
        }
    }
    while(q--){
        int u,k;
        cin>>u>>k;
        cout<<kthParent(u,k)<<endl;
    }
    return 0;
}
