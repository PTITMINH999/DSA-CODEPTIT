#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
vector<int> a[1001];
bool visited[1001];
int n,m;
void reset(){
    for(int i=0;i<1001;i++) a[i].clear();
    memset(visited,false,sizeof(visited));
}
void bfs(int u){
    queue<int> q;
    q.push(u);
    visited[u]=true;
    while(q.size()){
        int x=q.front(); q.pop();
        for(int v:a[x]){
            if(!visited[v]){
                q.push(v);
                visited[v]=true;
            }
        }
    }
}
void tplt(){
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            ++cnt;
            bfs(i);
        }
    }
    cout<<cnt<<endl;
}
int main(){
    faster();
    int t; cin>>t;
    while(t--){
        reset();
        cin>>n>>m;
        while(m--){
            int x,y; cin>>x>>y;
            a[x].push_back(y);
            a[y].push_back(x);
        }
        tplt();
    }
}