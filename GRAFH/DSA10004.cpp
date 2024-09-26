#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
int parent[1001];
int find(int v){
    if(v==parent[v]) return v;
    return parent[v]=find(parent[v]);
}
bool check(vector<pair<int,int>>&vp){
    int u,v;
    for(auto x:vp){
        u=find(x.first);
        v=find(x.second);
        if(u==v) return 1;
        parent[u]=v;
    }
    return 0;
}
int main(){
    int t; cin>>t;
    while(t--){
        int n,m; cin>>n>>m;
        for(int i=1;i<=n;i++) parent[i]=i;
        vector<pair<int,int>> a;
        while(m--){
            int x,y; cin>>x>>y;
            a.push_back({x,y});
        }
        if(check(a)) cout<<"YES\n";
        else cout<<"NO\n";
    }
}