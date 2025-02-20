#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t; cin>>t; while(t--)
#define ll long long
//dp[i][j]:  số bước ít nhất biến đổi xâu s1 độ dài i -> độ dài j  
int main(){
    faster();
    run(){
        string s1,s2; cin>>s1>>s2;
        int n=s1.size();
        int m=s2.size();
        int dp[n+1][m+1]={};
        for(int i=0;i<=n;i++) dp[i][0]=i;
        for(int j=0;j<=m;j++) dp[0][j]=j;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1]) dp[i][j]=dp[i-1][j-1];
                else{
                    dp[i][j]=min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]))+1;
                }
                /*
                dp[i-1][j]: insert;
                dp[i][j-1]:delete;
                dp[i-1][j-1]:replace;
                */
            }
        }
        cout<<dp[n][m]<<endl;
    }
}