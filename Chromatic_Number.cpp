#include<bits/stdc++.h>
using namespace std;
const int N=50;
bool adj[N][N];
int color[N];
int n,m;
bool isSafe(int node,int c){
    for(int i=0;i<n;i++){
        if(adj[node][i] && color[i]==c)return false;
    }
    return true;
}
bool solve(int node,int maxColor){
    if(node==n)return true;
    for(int c=1;c<=maxColor;c++){
        if(isSafe(node,c)){
            color[node]=c;
            if(solve(node+1,maxColor))return true;
            color[node]=0;
        }
    }
    return false;
}
int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        u--;v--;
        adj[u][v]=adj[v][u]=1;
    }
    for(int c=1;c<=n;c++){
        memset(color,0,sizeof(color));
        if(solve(0,c)){
            cout<<"Chromatic Number : "<<c<<endl;
            break;
        }
    }
    return 0;
}
