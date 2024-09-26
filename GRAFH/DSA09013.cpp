#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
int n,m;
vector<int> a[1001];
bool visited[1001];
vector<pair<int,int>> edge;
void dfs(int u){
    visited[u]=true;
    for(int v:a[u]){
        if(!visited[v]){
            dfs(v);
        }
    }
}
void dfs2(int u,int s,int t){
    visited[u]=true;
    for(int v:a[u]){
        // Neu xet phai canh muon loai bo thi ko xet
        if(u==s && v==t || u==t && v==s) continue;
        if(!visited[v]) dfs2(v,s,t);
    }
}
void canhcau(){
    int tplt=0;
    memset(visited,false,sizeof(visited));
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            ++tplt;
            dfs(i);
        }
    }
    for(auto it:edge){
        int x=it.first, y=it.second;
        // loai bo canh(x,,y)
        memset(visited,false,sizeof(visited));
        int dem=0;
        for(int j=1;j<=n;j++){
            if(!visited[j]){
                ++dem;
                dfs2(j,x,y);
            }
        }
        if(dem>tplt){
            if(x<y) cout<<x<<" "<<y<<" ";
            else cout<<y<<" "<<x<<" ";
        }
    }
}
int main(){
    faster();
    int t; cin>>t;
    while(t--){
        for(int i=0;i<1001;i++) a[i].clear();
        edge.clear();
        cin>>n>>m;
        int x,y;
        for(int i=0;i<m;i++){
            cin>>x>>y;
            a[x].push_back(y);
            a[y].push_back(x);
            edge.push_back({x,y});
        }
        canhcau();
        cout<<endl;
    }
}