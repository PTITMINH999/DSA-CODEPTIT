#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
vector<int> a[1005];
int color[1005];
bool dfs(int u){
    color[u]=1;
    for(int v:a[u]){
        if(color[v]==0){// mau xam
            if(dfs(v)) return true;
        }
        else if(color[v]==1) return true;
    }
    color[u]=2;//mau den
    return false;
}
int check(int n){
    for(int i=1;i<=n;i++){
        if(color[i]==0){
            if(dfs(i)) return 1;
        }
    }
    return 0;
}
int main(){
    faster();
    int t; cin>>t;
    while(t--){
        int n,m; cin>>n>>m;
        for(int i=0;i<1005;i++) a[i].clear();
        memset(color,0,sizeof(color));
        for(int i=0;i<m;i++){
            int x,y; cin>>x>>y;
            a[x].push_back(y);
        }
        if(check(n)) cout<<"YES\n";
        else cout<<"NO\n";
    }
}
