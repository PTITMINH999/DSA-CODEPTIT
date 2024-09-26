#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
int n,m;
vector<int> a[1001];
int color[1001];
// 0:red 1:blue
bool bfs(int u){
    queue<int> q;
    q.push(u);
    color[u]=0;// red;
    while(q.size()){
        int x=q.front();q.pop();
        for(int v:a[x]){
            if(color[v]==-1){
                color[v]=1-color[x];
                q.push(v);
            } 
            else if(color[v]==color[x]) return false;
        }
    }
    return true;
}
int main(){
    faster();
    int t; cin>>t;
    while(t--){
        cin>>n>>m;
        for(int i=0;i<1001;i++) a[i].clear();
        memset(color,-1,sizeof(color));
        while(m--){
            int x,y; cin>>x>>y;
            a[x].push_back(y);
            a[y].push_back(x);
        }
        int ok=1;
        for(int i=1;i<=n;i++){
            if(color[i]==-1){
                if(!bfs(i)){
                    ok=0;
                    break;
                }
            }
        }
        if(ok==1) cout<<"YES\n";
        else cout<<"NO\n";
    }
}
