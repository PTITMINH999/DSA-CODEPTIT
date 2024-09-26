#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
vector<int> adj[1001];
bool visited[1001];
int n,m;
void reset(){
    for(int i=0;i<1001;i++) adj[i].clear();
    memset(visited,false,sizeof(visited));
}
void dfs(int u){
    visited[u]=true;
    for(int v:adj[u]){
        if(!visited[v]){
            dfs(v);
        }
    }
}
int tplt(){
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            cnt++;
            dfs(i);
        }
    }
   return cnt;
}
int main(){
    faster();
    int t; cin>>t;
    while(t--){
        cin>>n>>m;
        reset();
        while(m--){
            int x,y;
            cin>>x>>y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        cout<<tplt()<<endl;
    }
}