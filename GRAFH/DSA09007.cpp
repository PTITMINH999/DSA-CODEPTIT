#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
vector<int> adj[1001];
bool visited[1001];
int parent[1001];
void bfs(int u){
    queue<int> q;
    q.push(u); visited[u]=true;
    while(!q.empty()){
        int x=q.front();
        q.pop();
        for(int v:adj[x]){
            if(!visited[v]){
                q.push(v);
                parent[v]=x;
                visited[v]=true;
            }
        }
    }
}
void path(int s,int t){
    bfs(s);
    if(!visited[t]) cout<<-1;
    else{
        vector<int> res;
        while(t!=s){
            res.push_back(t);
            t=parent[t];
        }
        res.push_back(s);
        reverse(res.begin(),res.end());
        for(int i:res) cout<<i<<' ';
    }
}
int main(){
    int t; cin>>t;
    while(t--){
        int n,m,u,v;
        cin>>n>>m>>u>>v;
        memset(visited,false,sizeof(visited));
        memset(parent,0,sizeof(parent));
        for(int i=0;i<1001;i++) adj[i].clear();
        while(m--){
            int a,b; cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        path(u,v);
        cout<<endl;
    }
}