#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t; cin>>t; while(t--)
#define ll long long
int main(){
    faster();
    run(){
        int n,v;
        cin>>n>>v;
        int a[n+1],c[n+1];
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int j=1;j<=n;j++) cin>>c[j];
        int dp[n+1][n+1]={};
        for(int i=1;i<=n;i++){
            for(int j=1;j<=v;j++){
                dp[i][j]=dp[i-1][j];
                if(j>=a[i]) dp[i][j]=max(dp[i][j],dp[i-1][j-a[i]]+c[i]);
            }
        }
        cout<<dp[n][v]<<endl;
    }
}