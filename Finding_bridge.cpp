#include<bits/stdc++.h>
using namespace std;
const int N=200005;
vector<int>v[N];
int in[N],low[N],vis[N];
int timer=0;
void dfs(int node,int par){
    vis[node]=1;
    in[node]=low[node]=++timer;
    for(int child:v[node]){
        if(child==par)continue;
        if(vis[child])low[node]=min(low[node],low[child]);
        else{
            dfs(child,node);
            low[node]=min(low[node],low[child]);
            if(low[node]<low[child]){
                cout<<node<<" "<<child<<endl;
            }
        }
    }
}
int main(){
    freopen("input.txt","r",stdin);
    int n,m,a,b;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i=1;i<=n;i++){
        if(!vis[i])dfs(i,-1);
    }
    return 0;
}
