#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t; cin >> t; while (t--)
#define pb(x) push_back(x);
bool check[100001];
vector<int> a[100001];
int n,m,cnt=0;
void dfs(int u){
    check[u]=true;
    cnt++;
    for(int v:a[u]){
        if(!check[v]) dfs(v);
    }
}
int main(){
    faster();
    run(){
        memset(check,false,sizeof(check));
        for(int i=0;i<100001;i++) a[i].clear();
        cin>>n>>m;
        while(m--){
            int x,y; cin>>x>>y;
            a[x].pb(y);
            a[y].pb(x);
        }
        bool ok=1;
        for(int i=1;i<=n;i++){
           if(!check[i]){
                cnt=0;
                dfs(i);
                if(cnt!=n){
                ok=0;break;
            }
            }
            // if(cnt!=n){
            //     ok=0;break;
            // }
        }
        if(ok==1) cout<<"YES\n";
        else cout<<"NO\n";
    }
}