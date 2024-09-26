#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t; cin>>t; while(t--)
int n,m,st,en;
vector<int> a[1001];
bool visited[1001];
int parent[1001];
bool dfs(int u){
    visited[u]=true;
    for(int v:a[u]){
        if(!visited[v]){
            parent[v]=u;
            if(dfs(v)) return true;
        }
        else if(v!= parent[u]){
            st=v; en=u;
            return true;
        }
    }
    return false;
}
int main(){
    run(){
        cin>>n>>m;
        memset(visited,false,sizeof(visited));
        for(int i=0;i<1001;i++){
            a[i].clear();
            parent[i]=0;
        }
        while(m--){
            int c,d; cin>>c>>d;
            a[c].push_back(d);
            a[d].push_back(c);
        }
        bool ok=0;
        if(dfs(1)){
            ok=1;
            vector<int> cycle;
            cycle.push_back(st);
            while(en!=st){
                cycle.push_back(en);
                en=parent[en];
            }
            cycle.push_back(st);
            reverse(cycle.begin(),cycle.end());
            for(int x:cycle) cout<<x<<" "; 
        }
        if(ok==0) cout<<"NO";
        cout<<endl;
    }
}
