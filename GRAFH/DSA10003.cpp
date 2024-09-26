#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
int main(){
    faster();
    int t; cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        int deg[1001]={};
        while(m--){
            int u,v; cin>>u>>v;
            deg[u]++;
            deg[v]++;
        }
        int cnt=0;
        for(int i=1;i<=n;i++){
            cnt+= deg[i]%2;
        }
        if(cnt==0) cout<<"2\n";
        else if(cnt==2) cout<<"1\n";
        else cout<<"0\n";
    }
}