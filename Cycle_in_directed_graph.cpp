#include <bits/stdc++.h>
using namespace std;
vector<int>v[100001];
int vis[100001];
bool dfs(int node){
    vis[node]=1;
    for(int child:v[node]){
        if(!vis[child]){
            if(dfs(child)==true)return true;
        }
        else{
            if(vis[child]==1)return true;
        }
    }
    vis[node]=2;
    return false;
}
int main(){
    //freopen("input.txt","r",stdin);
    int node,edge,x,y;
    cin>>node>>edge;
    while(edge--){
        cin>>x>>y;
        v[x].push_back(y);
    }
    bool antor=dfs(1);
    if(antor)cout<<"Cycle"<<endl;
    else cout<<"Not cycle"<<endl;
    return 0;
}
/*
Input:
4 4
2 3
1 2
3 4
4 1
*/
