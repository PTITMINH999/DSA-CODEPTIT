#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t; cin >> t; while (t--)
bool check[100001];
vector<int> a[100001];
int dem=0;
void dfs(int u){
    check[u]=true;
    dem++;
    for(int v:a[u]){
        if(!check[v]) dfs(v);
    }
}
int main(){
    faster();
    run(){
        for(int i=0;i<100001;i++) a[i].clear();
        memset(check,false,sizeof(check));
        int ans=0;
        int n,m; cin>>n>>m;
        while(m--){
            int x,y; cin>>x>>y;
            a[x].push_back(y);
            a[y].push_back(x);
        }
        int k=0 ;
        for(int i=1;i<=n;i++){
            if(!check[i]){
                dem=0;
                dfs(i);
                ans=max(ans,dem);
            }
        }
        cout<<ans<<endl;
    }
}