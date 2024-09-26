#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t; cin>>t; while(t--)
int main(){
    faster();
    run(){
        int n,m,k; cin>>n>>m>>k;
        string a,b,c; cin>>a>>b>>c;
        int dp[n+5][m+5][k+5];
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                for(int z=1;z<=k;z++){
                    if(a[i-1]==b[j-1] && a[i-1]==c[z-1])
                        dp[i][j][z]=dp[i-1][j-1][z-1]+1;
                    else 
                        dp[i][j][z]=max(dp[i-1][j][z],max(dp[i][j-1][z],dp[i][j][z-1]));
                }
            }
        }
        cout<<dp[n][m][k]<<endl;
    }
}