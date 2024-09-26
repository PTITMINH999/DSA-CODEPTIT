#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
int n,m;
vector<int> a[1001];
bool visited[1001];
void dfs(int u){
    visited[u]=true;
    for(int v:a[u]){
        if(!visited[v]){
            dfs(v);
        }
    }
}
void dinhtru(){
    int tplt=0;
    memset(visited,false,sizeof(visited));
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            ++tplt;
            dfs(i);
        }
    }
    for(int i=1;i<=n;i++){
        memset(visited,false,sizeof(visited));
        visited[i]=true;// loai bo i khoi do thi
        int dem=0;
        for(int j=1;j<=n;j++){
            if(!visited[j]){
                ++dem;
                dfs(j);
            }
        }
        if(dem>tplt) cout<<i<<' ';
    }
}
int main(){
    faster();
    int t; cin>>t;
    while(t--){
        for(int i=0;i<1001;i++) a[i].clear();
        cin>>n>>m;
        while(m--){
            int x,y; cin>>x>>y;
            a[x].push_back(y);
            a[y].push_back(x);
        }
        dinhtru();
        cout<<endl;
    }
}
