#include<bits/stdc++.h>
using namespace std;
vector<int>v[10001],ans;
int mp[10001];
void bfs(int n){
    queue<int>q;
    for(int i=1;i<=n;i++)if(!mp[i])q.push(i);
    while (!q.empty())
    {
        int cur=q.front();
        q.pop();
        ans.push_back(cur);
        for(int child:v[cur]){
            mp[child]--;
            if(!mp[child])q.push(child);
        }
    }
    cout<<"The topological sort is : ";
    for(auto it:ans)cout<<it<<" ";
}
int main(){
    freopen("input.txt","r",stdin);
    int node,edge,x,y;
    cin>>node>>edge;
    while (edge--){
        cin>>x>>y;
        v[x].push_back(y);
        mp[y]++;
    }
    bfs(node);
    return 0;
}
/*
Input:
7 6
1 2
2 5
2 6
6 7
3 4
4 5
*/
