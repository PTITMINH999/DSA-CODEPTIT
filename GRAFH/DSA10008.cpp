#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
int n,m,s;
vector<pair<int,int>>A[1001];
void dijkstra(int s){
    // Mảng lưu khoảng cách đường đi
    vector<int> d(n+1,1e9);
    d[s]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
    //{khoảng cách,đỉnh};
    q.push({0,s});
    while(!q.empty()){
        // chọn ra đỉnh có khoảng cách từ s nhỏ nhất
        pair<int,int> t=q.top();q.pop();
        int u=t.second;
        int kc=t.first;
        if(kc>d[u]) continue;
        // Cập nhật khoảng cách từ s tới mọi đỉnh kề với u;
        for(auto x:A[u]){
            int v=x.first;
            int w=x.second;
            if(d[v]>d[u]+w){
                d[v]=d[u]+w;
                q.push({d[u],v});
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<d[i]<<" ";
    }
}
int main(){
    int t; cin>>t;
    while(t--){
        cin>>n>>m>>s;
        for(int i=0;i<1001;i++) A[i].clear();
        while(m--){
            int x,y,w; cin>>x>>y>>w;
            A[x].push_back({y,w});
            A[y].push_back({x,w});
        }
        dijkstra(s);
        cout<<endl;
    }
}