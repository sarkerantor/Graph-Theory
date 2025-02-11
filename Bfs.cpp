#include<bits/stdc++.h>
using namespace std;
vector<int>v[10001];
int vis[10001],dis[10001];
void bfs(int n){
    queue<int>q;
    vis[n]=1;
    dis[n]=0;
    q.push(n);
    while (!q.empty())
    {
        int cur=q.front();
        q.pop();
        for(int child:v[cur]){
            if(!vis[child]){
                dis[child]=dis[cur]+1;
                vis[child]=1;
                q.push(child);
            }
        }
    }
}
int main(){
    freopen("input.txt","r",stdin);
    int node,edge,x,y;
    cin>>node>>edge;
    while (edge--){
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    bfs(1);
    for(int i=1;i<=node;i++)cout<<"Distance of node "<<i<<" = "<<dis[i]<<endl;
    return 0;
}
/*
Input:
6 5
1 4
2 4
3 4
4 5
5 6
*/
