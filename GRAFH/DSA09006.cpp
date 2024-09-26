#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
vector<int> adj[1001];
bool visited[1001];
int parent[1001];
void dfs(int u){
    visited[u]=true;
    for(int v:adj[u]){
        if(!visited[v]){
            dfs(v);
            parent[v]=u;
        }
    }
}
void path(int s,int t){
    dfs(s);
    if(!visited[t]) cout<<-1;
    else{
        // truy vet duong di 
        vector<int> ans;
        while(t!=s){
            ans.push_back(t);
            t=parent[t];
        }
        ans.push_back(s);
        reverse(ans.begin(),ans.end());
        for(int x:ans) cout<<x<<' ';
    }
}
int main(){
    faster();
    int t; cin>>t;
    int n,m,u,v;
    while(t--){
        int n,m,u,v;
        cin>>n>>m>>u>>v;
        memset(visited,false,sizeof(visited));
        memset(parent,0,sizeof(parent));
        for(int i=0;i<1001;i++) adj[i].clear();
        while(m--){
            int a,b;
            cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
       // dfs(u);
        path(u,v);
        cout<<endl;
    }
}