#include<bits/stdc++.h>
using namespace std;
vector<int>v[10001],path;
int vis[10001];
int n;
bool hamiltonian(int node,int count){
    path.push_back(node);
    if(count==n){
        if(find(v[node].begin(),v[node].end(),path[0])!=v[node].end()){
            cout<<"Hamiltonian cycle exist :";
            for(int i:path)cout<<i<<" ";
            cout<<path[0]<<endl;
        }
        else{
            cout<<"Hamiltonian Path exist : ";
            for(int i:path)cout<<i<<" ";
            cout<<endl;
        }
    }
    vis[node]=1;
    bool found=false;
    for(int child:v[node]){
        if(!vis[child]){
            found|=hamiltonian(child,count+1);
        }
    }
    vis[node]=0;
    path.pop_back();
    return found;
}
int main(){
    //freopen("input.txt","r",stdin);
    int edge,a,b;
    cin>>n>>edge;
    while(edge--){
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    bool found=false;
    for(int i=0;i<n;i++){
        found|=hamiltonian(i,1);
    }
    if(!found)cout<<"Hamilton path and cycle not exist."<<endl;
    return 0;
}
/*
Input:
4 6
0 1
0 2
0 3
1 2
1 3
2 3
*/
