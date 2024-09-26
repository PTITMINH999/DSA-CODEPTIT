#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
int main(){
    faster();
    int t; cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        int deg1[1001]={};// bán bậc ra
        int deg2[1001]={};// bán bậc vào
        while(m--){
            int u,v; cin>>u>>v;
            deg1[u]++;
            deg2[v]++;
        }
        int ok=1;
        for(int i=1;i<=n;i++){
            if(deg1[i]!=deg2[i]){
                ok=0;
                break;
            }
        }
        if(ok) cout<<"1\n";
        else cout<<"0\n";
    }
}