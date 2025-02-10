#include<bits/stdc++.h>
using namespace std;
vector<int>v[10001];
int main(){
    //freopen("input.txt","r",stdin);
    int node,edge,x,y;
    cin>>node>>edge;
    while (edge--)
    {
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for(int i=1;i<=node;i++){
        cout<<i<<" -> ";
        for(int j=0;j<v[i].size();j++)cout<<v[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
/*
Input:
5 4
1 2
1 3
3 4
3 5
*/
