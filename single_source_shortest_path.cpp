#include<bits/stdc++.h>
using namespace std;
vector<int>v[10001];
int vis[10001],dis[10001];
void dfs(int node,int d){
    vis[node]=1;
    dis[node]=d;
    for(int i:v[node]){
        if(!vis[i])dfs(i,d+1);
    }
}
int main(){
    freopen("input.txt","r",stdin);
    int node,edge,x,y;
    cin>>node>>edge;
    while (edge--)
    {
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    int a;
    cin>>a;
    dfs(a,0);
    for(int i=1;i<=node;i++){
        cout<<"The distance between "<<i<<" to "<<x<<" is "<<dis[i]<<endl;
    }
    return 0;
}
/*
Input:
7 6
1 2
2 4
2 5
1 3
3 6
3 7
*/
