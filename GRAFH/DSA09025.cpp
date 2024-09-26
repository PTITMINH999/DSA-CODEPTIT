#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
vector<int> a[1005];
bool visited[1005];
int parent[1005];
void dfs(int u){
    visited[u]=true;
    for(int v:a[u]){
        if(!visited[v]){
            dfs(v);
            parent[v]=u;
        }
    }
}
void path(int s,int t){
    dfs(s);
    if(!visited[t]) cout<<"-1";
    else{
        vector<int> r;
        while(t!=s){
            r.push_back(t);
            t=parent[t];
        }
        r.push_back(s);
        reverse(r.begin(),r.end());
        for(int x:r) cout<<x<<" ";
    }
}
int main(){
    faster();
    int t; cin>>t;
    while(t--){
        int n,m,u,v;
        cin>>n>>m>>u>>v;
        memset(visited,false,sizeof(visited));
        memset(parent,0,sizeof(parent));
        for(int i=0;i<1005;i++) a[i].clear();
        while(m--){
            int x,y; cin>>x>>y;
            a[x].push_back(y);
        }
        path(u,v);
        cout<<endl;
    }
}