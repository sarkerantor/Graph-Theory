#include<bits/stdc++.h>
using namespace std;
void dfs1(int node,vector<vector<int>>&adj,vector<bool>&vis,stack<int>&s){
    vis[node]=true;
    for(int child:adj[node]){
        if(!vis[child])dfs1(child,adj,vis,s);
    }
    s.push(node);
}
void dfs2(int node,vector<vector<int>>&radj,vector<bool>&vis,vector<int>&ans){
    vis[node]=true;
    ans.push_back(node);
    for(int child:radj[node]){
        if(!vis[child])dfs2(child,radj,vis,ans);
    }
}
int main(){
    //freopen("input.txt","r",stdin);
    int node,edge,a,b;
    cin>>node>>edge;
    vector<vector<int>>adj(node),radj(node);
    while(edge--){
        cin>>a>>b;
        adj[a].push_back(b);
        radj[b].push_back(a);
    }
    vector<bool>vis(node,false);
    stack<int>s;
    for(int i=0;i<node;i++){
        if(!vis[i])dfs1(i,adj,vis,s);
    }
    fill(vis.begin(),vis.end(),false);
    vector<vector<int>>scc;
    while(!s.empty()){
        int n=s.top();
        s.pop();
        if(!vis[n]){
            vector<int>ans;
            dfs2(n,radj,vis,ans);
            scc.push_back(ans);
        }
    }
    cout<<"Strongly connected components : \n";
    for(int i=0;i<scc.size();i++){
        for(int it:scc[i]){
            cout<<it<<" ";
        }
        cout<<endl;
    }
    return 0;
}
/*
Input:
5 5
0 2
2 1
1 0
0 3
3 4
*/
