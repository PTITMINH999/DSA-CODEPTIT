#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
int n,m;
vector<int> a[1001],r_a[1001];
bool visited[1001];
stack<int> st;
void dfs1(int u){
    visited[u]=true;
    for(int v:a[u]){
        if(!visited[v]){
            dfs1(v);
        }
    }
    st.push(u); // da duyet xong dinh u
}
void dfs2(int u){
    visited[u]=true;
    for(int v:r_a[u]){
        if(!visited[v]) dfs2(v);
    }
}
void SCC(){
    for(int i=1;i<=n;i++){
        if(!visited[i]) dfs1(i);
    }
    memset(visited,false,sizeof(visited));
    int cnt=0;
    while(!st.empty()){
        int u=st.top();st.pop();
        if(!visited[u]){
            cnt++;
            dfs2(u);
        }
    }
    if(cnt==1) cout<<"YES\n";
    else cout<<"NO\n";
}
int main(){
    faster();
    int t; cin>>t;
    while(t--){
        cin>>n>>m;
        for(int i=0;i<1001;i++){
            a[i].clear(); 
            r_a[i].clear();
        }
        memset(visited,false,sizeof(visited));
        for(int i=0;i<m;i++){
            int x,y; cin>>x>>y;
            a[x].push_back(y);
            r_a[y].push_back(x);
        }
        SCC();
    }
}