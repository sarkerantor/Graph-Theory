#include<bits/stdc++.h>
using namespace std;
const int N=505;
vector<int>adj[N];
int vis[N],paair[N];
bool kuhn(int node){
    for(int child:adj[node]){
        if(vis[child])continue;
        vis[child]=1;
        if(paair[child]==-1 || kuhn(paair[child])){
            paair[child]=node;
            return true;
        }
    }
    return false;
}
int main(){
    //freopen("input.txt","r",stdin);
    int n,m,k,a,b,ans=0;
    cin>>n>>m>>k;
    for(int i=0;i<k;i++){
        cin>>a>>b;
        adj[a].push_back(b);
    }
    memset(paair,-1,sizeof(paair));
    for(int i=1;i<=n;i++){
        memset(vis,0,sizeof(vis));
        if(kuhn(i))ans++;
    }
    cout<<ans<<endl;
    for(int i=1;i<=m;i++){
        if(paair[i]!=-1)cout<<paair[i]<<" "<<i<<endl;
    }
    return 0;
}
