#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t; cin>>t; while(t--)
#define ll long long
// dp[i][j]: hình vuông có kích thước từ 0,0->i,j
int main(){
    faster();
    run(){
        int n,m; cin>>n>>m;
        int a[n+1][m+1];
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
            }
        }
        int dp[n+1][m+1]={};
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(a[i][j]==1){
                    dp[i][j]=min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1]))+1;
                }
                ans=max(ans,dp[i][j]);
            }
        }
        cout<<ans<<endl;
    }
}