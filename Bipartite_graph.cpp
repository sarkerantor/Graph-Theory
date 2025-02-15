#include <bits/stdc++.h>
using namespace std;
vector<int>v[100001];
int vis[100001],col[100001];
bool dfs(int node,int c){
    vis[node]=1;
    col[node]=c;
    for(int child:v[node]){
        if(!vis[child]){
            if(dfs(child,c^1)==false)return false;
        }
        else {
            if(col[child]==col[node])return false;
        }
    }
    return true;
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
    bool isbipartite=true;
    for(int i=1;i<=node;i++){
        if(!vis[node]){
            if(dfs(i,1)==false){
                isbipartite=false;
                break;
            }
        }
    }
    if(isbipartite)cout<<"Bipartite Graph"<<endl;
    else cout<<"Not a Bipartite Graph"<<endl;
    return 0;
}
/*
Input:
6 6
1 4
1 5
2 5
2 3
5 6
3 6
*/
