#include<bits/stdc++.h>
using namespace std;
vector<int>v[22],path;
int vis[22];
int n;
bool hamiltonian(int node,int count){
    vis[node]=1;
    path.push_back(node);
    if(count==n){
        if(find(v[node].begin(),v[node].end(),path[0])!=v[node].end()){
            cout<<"Hamiltonian cycle exist : ";
            for(int val:path)cout<<val<<" ";
            cout<<path[0]<<endl;
        }
        else{
            cout<<"Hamiltonian Path exist : ";
            for(int val:path)cout<<val<<" ";
            cout<<endl;
        }
        vis[node]=0;
        path.pop_back();
        return true;
    }
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
    for(int i=1;i<=n;i++){
        found|=hamiltonian(i,1);
    }
    if(!found)cout<<"Hamilton Path and Circuit not exist."<<endl;
    return 0;
}
