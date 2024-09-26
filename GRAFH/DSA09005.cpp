#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
vector<int> adj[1001];// danh sach ke
bool visited[1001];
void bfs(int u){
    queue<int> q;
    q.push(u);
    visited[u]=1;// danh dau dinh u da dc tham
    while(!q.empty()){
        int x=q.front();
        q.pop();
        cout<<x<<' ';
        //duyet cac dinh ke voi x ma chua duoc tham
        for(int y:adj[x]){
            if(!visited[y]){// neu y chua duoc tham 
                q.push(y);
                visited[y]=1;
            }
        }
    }
}
int main(){
    faster();
    int t; cin>>t;
    while(t--){
        int n,m,u;
        cin>>n>>m>>u;
        memset(visited,0,sizeof(visited));
        for(int i=0;i<1001;i++) adj[i].clear();
        while(m--){
            int a,b; cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        bfs(u);
        cout<<endl;
    }
}