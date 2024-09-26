#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
vector<int> a[1005];
bool visited[1005];
void bfs(int u){
    queue<int> q;
    q.push(u);
    visited[u]=true;
    while(!q.empty()){
        int x=q.front(); q.pop();
        cout<<x<<' ';
        for(int y:a[x]){
            if(!visited[y]){
                q.push(y);
                visited[y]=true;
            }
        }
    }
}
int main(){
    int t; cin>>t;
    while(t--){
        memset(visited,false,sizeof(visited));
        for(int i=0;i<1005;i++) a[i].clear();
        int n,m,u; cin>>n>>m>>u;
        for(int i=0;i<m;i++){
            int x,y; cin>>x>>y;
            a[x].push_back(y);
        }
        bfs(u);
        cout<<endl;
    }
}