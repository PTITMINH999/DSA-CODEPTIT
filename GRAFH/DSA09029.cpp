#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t; cin>>t; while(t--)
int n,m;
bool check[1001];
vector<int> a[1001];
bool ok;
void dfs(int u,int cnt){// cnt: so dinh da di qua
    if(cnt==n) ok=true;
    check[u]=true;
    for(int x:a[u]){
        if(!check[x]) dfs(x,cnt+1);
    }
    check[u]=false;
}
int hamilton(){
    ok=false;
    for(int i=1;i<=n;i++){
        if(!check[i]){
            dfs(i,1);
        }
        if(ok) return 1;
    }
    return 0;
}
int main(){
    faster();
    run(){
        cin>>n>>m;
        memset(check,false,sizeof(check));
        for(int i=0;i<1001;i++) a[i].clear();
        for(int i=0;i<m;i++){
            int x,y; cin>>x>>y;
            a[x].push_back(y);
            a[y].push_back(x);
        }
        cout<<hamilton()<<endl;
    }
}