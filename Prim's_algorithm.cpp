#include<bits/stdc++.h>
using namespace std;
const int N=200005;
vector<pair<int,int>>v[N];
int vis[N];
int prim(int start){
    int ans=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,start});
    while(!pq.empty()){
        pair<int,int>cur=pq.top();
        pq.pop();
        int node=cur.second,weight=cur.first;
        if(vis[node])continue;
        vis[node]=1;
        ans+=weight;
        for(auto it:v[node]){
            int nod=it.first,wt=it.second;
            if(!vis[nod])pq.push({wt,nod});
        }
    }
    return ans;
}
int main(){
    //freopen("input.txt","r",stdin);
    int n,m,a,b,w;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>a>>b>>w;
        v[a].push_back({b,w});
        v[b].push_back({a,w});
    }
    cout<<prim(1)<<endl;
    return 0;
}
