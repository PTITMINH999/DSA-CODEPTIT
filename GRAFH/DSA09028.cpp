#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t; cin>>t; while(t--)
int n,m,mau;
int color[1001];
bool check[1001];
vector<int> a[1001];
bool bfs(int u){
    queue<int> q;
    check[u]=true;
    q.push(u); int maxi=1;
    while(q.size()){
        int x=q.front();q.pop();
        for(int v:a[x]){
            if(color[v]==color[x]) color[v]++;
            maxi=max(maxi,max(color[v],color[x]));
            if(maxi>mau) return false;
            if(!check[v]){
                q.push(v); check[v]=true;
            } 
        }
    }
    return true;
}
void solve(){
    int ok=1;
    for(int i=1;i<=n;i++){
        if(!check[i]){
            if(!bfs(i)){
                ok=0;break;
            }
        }
    }
    if(ok) cout<<"YES\n";
    else cout<<"NO\n";
}
int main(){
    faster();
    run(){
        for(int i=0;i<1001;i++){
            a[i].clear();
            color[i]=1;
        }
        memset(check,false,sizeof(check));
        cin>>n>>m>>mau;
        for(int i=0;i<m;i++){
            int x,y; cin>>x>>y;
            a[x].push_back(y);
            a[y].push_back(x);
        }
        solve();
    }
}