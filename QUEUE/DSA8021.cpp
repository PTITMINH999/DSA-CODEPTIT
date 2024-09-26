#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t;cin>>t;while(t--)
#define ll long long
bool check[1001][1001];
int A[1001][1001];
int m,n;
struct toado{
    int x,y,cnt;
};
int main(){
    faster();
    run(){
        memset(check,false,sizeof(check));
        cin>>m>>n;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=m;j++){
                cin>>A[i][j];
            }
        }
        check[1][1]=1;
        int ans=1e9;
        queue<toado> q;
        q.push({1,1,0});
        while(q.size()){
            toado f=q.front();q.pop();
            if(f.x==m && f.y==n){
                ans=min(ans,f.cnt);
                break;
            }
            if(f.x+ A[f.x][f.y]<=m && !check[f.x+A[f.x][f.y]][f.y]){
                check[f.x+A[f.x][f.y]][f.y]=1;
                q.push({f.x+A[f.x][f.y],f.y,f.cnt+1});
            }
            if(f.y+ A[f.x][f.y]<=m && !check[f.x][f.y+A[f.x][f.y]]){
                check[f.x][f.y+A[f.x][f.y]]=1;
                q.push({f.x,f.y+A[f.x][f.y],f.cnt+1});
            }
        }
        if(ans==1e9) cout<<-1<<endl;
        else cout<<ans<<endl;
    }
}