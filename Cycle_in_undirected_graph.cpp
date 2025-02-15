#include <bits/stdc++.h>
using namespace std;
vector<int>v[100001];
int vis[100001];
bool dfs(int node,int par){
    vis[node]=1;
    for(int child:v[node]){
        if(!vis[child]){
            if(dfs(child,node)==true)return true;
        }
        else{
            if(child!=par)return true;
        }
    }
    return false;
}
int main(){
    //freopen("input.txt","r",stdin);
    int node,edge,x,y;
    cin>>node>>edge;
    while(edge--){
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    bool antor=dfs(1,-1);
    if(antor)cout<<"Cycle"<<endl;
    else cout<<"Not cycle"<<endl;
    return 0;
}
/*
Input:
5 5
1 2
2 3
2 4
3 4
4 5
*/
