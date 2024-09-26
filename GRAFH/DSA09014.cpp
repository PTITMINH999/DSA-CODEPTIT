#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
vector<int> a[1005];
bool visited[1005];
//int parent[1005];
int n,m;
bool dfs(int u,int par){
    visited[u]=true;
    for(int v:a[u]){
        if(!visited[v]){
            if(dfs(v,u)) return true;
        }
        else if(v!=par){
            return true;
        }
    }
    return false;
}
int check(){
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            if(dfs(i,0)) return 1;
        }
    }
    return 0;
}
int main(){
    faster();
    int t;cin>>t;
    while(t--){
        cin>>n>>m;
        for(int i=0;i<1005;i++) a[i].clear();
        memset(visited,false,sizeof(visited));
        for(int i=0;i<m;i++){
            int x,y; cin>>x>>y;
            a[x].push_back(y);
            a[y].push_back(x);
        }
        if(check()) cout<<"YES\n";
        else cout<<"NO\n";
    }
}