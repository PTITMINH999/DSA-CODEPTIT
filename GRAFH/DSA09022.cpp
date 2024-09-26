#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
int n,m,u;
bool visited[1001];
vector<int> a[1001];
void dfs(int u){
    cout<<u<<' ';
    visited[u]=true;
    for(int v:a[u]){
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
        for(int i=0;i<1001;i++) a[i].clear();
        memset(visited,false,sizeof(visited));
        for(int i=0;i<m;i++){
            int x,y; cin>>x>>y;
            a[x].push_back(y);
        }
        dfs(u);
        cout<<endl;
    }
}