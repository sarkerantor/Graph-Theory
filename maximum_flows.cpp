#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
struct Edge{
    int to,rev;
    ll cap;
};
class Dinic{
    int n;
    vector<vector<Edge>>adj;
    vector<int>level,ptr;
public:
    Dinic(int n){
        this->n=n;
        adj.resize(n);
        level.resize(n);
        ptr.resize(n);
    }
    void add_edge(int u,int v,ll cap){
        adj[u].push_back({v,(int)adj[v].size(),cap});
        adj[v].push_back({u,(int)adj[u].size()-1,0});//reverse
    }
    bool bfs(int s,int t){
        fill(level.begin(),level.end(),-1);
        queue<int>q;
        q.push(s);
        level[s]=0;
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(auto &e:adj[u]){
                if(e.cap>0 && level[e.to]==-1){
                    level[e.to]=level[u]+1;
                    q.push(e.to);
                }
            }
        }
        return level[t]!=-1;
    }
    ll dfs(int u,int t,ll pushed){
        if(pushed==0)return 0;
        if(u==t)return pushed;
        for(int &i=ptr[u];i<(int)adj[u].size();i++){
            Edge &e=adj[u][i];
            if(level[e.to]==level[u]+1 && e.cap>0){
                ll tr=dfs(e.to,t,min(pushed,e.cap));
                if(tr>0){
                    e.cap-=tr;
                    adj[e.to][e.rev].cap+=tr;
                    return tr;
                }
            }
        }
        return 0;
    }
    ll max_flow(int s,int t){
        ll flow=0;
        while(bfs(s,t)){
            fill(ptr.begin(),ptr.end(),0);
            while(ll pushed=dfs(s,t,LLONG_MAX)){
                flow+=pushed;
            }
        }
        return flow;
    }
};
int main(){
    int n,m,u,v;
    cin>>n>>m;
    Dinic dinic(n);
    for(int i=0;i<m;i++){
        ll c;
        cin>>u>>v>>c;
        u--;v--;
        dinic.add_edge(u,v,c);
    }
    int source=0,terminate=n-1;
    cout<<dinic.max_flow(source,terminate)<<endl;
    return 0;
}
