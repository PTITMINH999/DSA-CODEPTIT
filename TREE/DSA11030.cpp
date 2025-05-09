#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t;cin>>t;while(t--)
#define ll long long
vector<int> a[1005];
bool visited[1005];
int res;
bool check;
void dfs(int u,int v, int cnt){
    if(check) return;
    visited[u]=1;
    if(u==v){
        check=1;
        res=cnt;
        return;
    }
    for(int &x:a[u]){
        if(!visited[x]) dfs(x,v,cnt+1);
    }
}
int main(){
    faster();
    run(){
        int n; cin>>n;
        n--;
        for(int i=0;i<=1005;i++) a[i].clear();
        while(n--){
            int x,y; cin>>x>>y;
            a[x].push_back(y);
            a[y].push_back(x);
        }
        int q; cin>>q;
        while(q--){
            int u,v; cin>>u>>v;
            res=0;
            check=0;
            dfs(u,v,0);
            cout<<res<<endl;
            memset(visited,0,sizeof(visited));
        }
    }
}