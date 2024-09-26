#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
vector<int> a[1001];
bool visited[1001];
int par[1001];
bool bfs(int u){
    queue<int> q;
    q.push(u);
    visited[u]=true;
    while(!q.empty()){
        int x=q.front();q.pop();
        for(int v:a[x]){
            if(!visited[v]){
                q.push(v);
                visited[v]=true;
                par[v]=x;
            }
            else if(v!=par[x]) return true;
        }
    }
    return false;
}
int check(int n){
    for(int i=1;i<=n;i++){
       if(!visited[i]){
            if(bfs(i)) return 1;
       }
    }
    return 0;
}
int main(){
    faster();
    int t; cin>>t;
    while(t--){
        int v; cin>>v;
        for(int i=0;i<1001;i++) a[i].clear();
        memset(visited,false,sizeof(visited));
        memset(par,0,sizeof(par));
        for(int i=1;i<=v-1;i++){
            int x,y; cin>>x>>y;
            a[x].push_back(y);
            a[y].push_back(x);
        }
        if(check(v)==1) cout<<"NO\n";
        else cout<<"YES\n";
    }
}