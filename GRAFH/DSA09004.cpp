#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
int n,m,u;// dinh,canh
vector<int> adj[1001];
bool visited[1001];
void dfs(int u){
    cout<<u<<" ";
    // danh dau u da duoc tham
    visited[u]=1;
    for(int v:adj[u]){
        //neu dinh v chua duoc tham
        if(!visited[v]){
            dfs(v);
        }
    }
}
int main(){
    faster();
    int t; cin>>t;
    while(t--){
        cin>>n>>m>>u;
        memset(visited,0,sizeof(visited));
        for(int i=1;i<=n;i++){
            adj[i].clear();
        }
        while(m--){
            int x,y; cin>>x>>y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        dfs(u);
        cout<<endl;
    }
}