#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
int n,m;
vector<int> a[1001];
bool check[1001];
int bfs(int u,int v){
    check[u]=true;
    queue<pair<int,int>> q;
    q.push({u,0});
    while(!q.empty()){
        pair<int,int> t=q.front();q.pop();
        int x=t.first;
        int kc=t.second;
        if(x==v) return kc;
        for(int b:a[x]){
            if(!check[b]){
                check[b]=true;
                q.push({b,kc+1});
            }
        }
    }
    return -1;
} 
int main(){
    faster();
    int t; cin>>t;
    while(t--){
        memset(check,false,sizeof(check));
        for(int i=0;i<1001;i++) a[i].clear();
        cin>>n>>m;
        while(m--){
            int x,y; cin>>x>>y;
            a[x].push_back(y);
        }
        int ans=0,cnt=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                memset(check,false,sizeof(check));
                if(i!=j){
                    int val=bfs(i,j);
                    if(val!=-1){
                        ans+=val; cnt++;
                    }
                }
            }
        }
        cout<<setprecision(2)<<fixed<< 1.0*ans/cnt<<endl;
    }
}