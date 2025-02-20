#include<bits/stdc++.h>
using namespace std;
const int inf=1e6;
int main(){
    vector<vector<int>>graph={{0,5,inf,9,1},
                            {5,0,2,inf,inf},
                            {inf,2,0,7,inf},
                            {9,inf,7,0,2},
                            {1,inf,inf,2,0}};
    int n=graph.size();
    vector<vector<int>>dist=graph;
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(dist[i][k]+dist[k][j]<dist[i][j]){
                    dist[i][j]=dist[i][k]+dist[k][j];
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(dist[i][j]==inf)cout<<"INF ";
            else cout<<dist[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
