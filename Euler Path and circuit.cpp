#include<bits/stdc++.h>
using namespace std;
vector<int>v[10001];
int vis[10001],degree[10001];
void dfs(int node){
    vis[node]=1;
    for(int child:v[node]){
        if(!vis[child])dfs(child);
    }
}
bool isconnected(int n){
    int st=-1;
    for(int i=0;i<n;i++){
        if(!v[i].empty()){
            st=i;
            break;
        }
    }
    if(st==-1)return true;
    dfs(st);
    for(int i=0;i<n;i++){
        if(!v[i].empty()&&!vis[i]){
            return false;
        }
    }
    return true;
}
void checkeuler(int n){
    if(!isconnected(n)){
        cout<<"Graph is not connected , so Euler path and circuit are not exist."<<endl;
        return;
    }
    int odd=0;
    for(int i=0;i<n;i++){
        if(degree[i]%2!=0)odd++;
    }
    if(odd==0)cout<<"Euler path and circuit exist."<<endl;
    else if(odd==2)cout<<"Euler path exist , but circuit not exist ."<<endl;
    else cout<<"Euler path and circuit not exist."<<endl;
}
int main(){
    //freopen("input.txt","r",stdin);
    int node,edge,a,b;
    cin>>node>>edge;
    while(edge--){
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
        degree[a]++;
        degree[b]++;
    }
    checkeuler(node);
}
/*
Input:
5 5
0 1
1 2
2 3
3 4
4 0
*/
