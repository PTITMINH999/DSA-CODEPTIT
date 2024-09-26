#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t; cin>>t; while(t--)
#define ll long long
int main(){
    faster();
        int c,n; cin>>c>>n;
        int w[n+1];
        for(int i=1;i<=n;i++) cin>>w[i];
        int dp[n+1][c+1]={};
        for(int i=1;i<=n;i++){
            for(int j=1;j<=c;j++){
                dp[i][j]=dp[i-1][j];
                if(j>=w[i]) dp[i][j]=max(dp[i][j],dp[i-1][j-w[i]]+w[i]);
            }
        }
        cout<<dp[n][c]<<endl;
}