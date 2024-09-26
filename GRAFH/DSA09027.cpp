#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
vector<int> a[1001];
bool visited[1001];
void reset(){
    for(int i=0;i<1001;i++) a[i].clear();
    memset(visited,false,sizeof(visited));
}
void dfs(int u){
    visited[u]=true;
    for(int v:a[u]){
        if(!visited[v]) dfs(v);
    }
}
int main(){
    faster();
    int t; cin>>t;
    while(t--){
        reset();
        int n,m; cin>>n>>m;
        while(m--){
            int x,y; cin>>x>>y;
            a[x].push_back(y);
            a[y].push_back(x);
        }
        int q; cin>>q;
        while(q--){
            int u,v; cin>>u>>v;
            dfs(u);
            if(visited[v]) cout<<"YES\n";
            else cout<<"NO\n";
        }
    }
}