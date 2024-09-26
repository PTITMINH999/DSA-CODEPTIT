#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
struct edge{
    int x,y,w;
};
const int INF=1e9;
int n,m;
vector<edge> canh;
vector<int> d(1005);
void in(){
    cin>>n>>m;
    while(m--){
        int u,v,w; cin>>u>>v>>w;
        canh.push_back({u,v,w});
    }
}
bool check(int s){
    d[s]=0;
    for(int i=1;i<=n-1;i++){
        for(edge e:canh){
            if(d[e.x]<INF){
                d[e.y]=min(d[e.y],d[e.x]+e.w);
            }
        }
    }
    bool ok=false;
    for(edge e:canh){
        if(d[e.x]<INF)
            if(d[e.y]>d[e.x]+e.w){
                ok=true;break;
            }
    }
    return ok;
}
void Bellmanford(){
    for(int i=0;i<1005;i++) d[i]=INF;
    bool ok=0;
    for(int i=1;i<=n;i++){
        if(d[i]==INF){
            if(check(i)){
                ok=1;break;
            }
        }
    }
   if(ok) cout<<"1"<<endl;
   else cout<<"0"<<endl;
}
int main(){
    int t; cin>>t;
    while(t--){
        canh.clear();
        in();
        Bellmanford();
    }
}