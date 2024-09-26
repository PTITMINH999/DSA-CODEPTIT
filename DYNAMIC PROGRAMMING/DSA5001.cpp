#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t; cin>>t; while(t--)
int main(){
    faster();
    run(){
        string x,y; 
        cin>>x>>y;
        int n=x.size(),m=y.size();
        int dp[n+1][m+1];
        for(int i = 0; i <= m; ++i) dp[0][i] = 0;
        for(int i = 0; i <= n; ++i) dp[i][0] = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(x[i]==y[j]) dp[i+1][j+1]=dp[i][j]+1;
                else dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);
            }
        }
        cout<<dp[n][m]<<endl;
    }
}