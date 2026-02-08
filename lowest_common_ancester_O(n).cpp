#include<bits/stdc++.h>
using namespace std;
vector<int>v[200005];
int parent[200005],vis[200005];
void dfs(int node,int par){
    vis[node]=1;
    parent[node]=par;
    for(int child:v[node]){
        if(!vis[child])dfs(child,node);
    }
}
vector<int>path(int node){
    vector<int>ans;
    while(node!=-1){
        ans.push_back(node);
        node=parent[node];
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
int main(){
    freopen("input.txt","r",stdin);
    int n,a,b;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1,-1);
    vector<int>path1=path(11);
    vector<int>path2=path(12);
    int sz1=path1.size(),sz2=path2.size(),lca=-1;
    for(int i=0;i<min(sz1,sz2);i++){
        if(path1[i]==path2[i])lca=path1[i];
        else break;
    }
    cout<<lca<<endl;
    return 0;
}
