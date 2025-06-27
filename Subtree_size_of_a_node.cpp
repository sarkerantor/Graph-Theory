#include<bits/stdc++.h>
using namespace std;
vector<int>v[10001];
int vis[10001],subtree[10001];
int dfs(int node){
    vis[node]=1;
    int count=1;
    for(int child:v[node]){
        if(!vis[child])count+=dfs(child);
    }
    subtree[node]=count;
    return count;
}
int main(){
    freopen("input.txt","r",stdin);
    int node,edge,a,b;
    cin>>node>>edge;
    while(edge--){
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1);
    for(int i=1;i<=node;i++)cout<<"The subtree size of node "<<i<<" is "<<subtree[i]<<endl;
    return 0;
}
/*
Input: 
8 7
1 2
2 3
3 4
3 5
1 6
6 7
6 8
*/
