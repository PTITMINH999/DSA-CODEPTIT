#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t; cin>>t; while(t--)
#define ll long long
int main(){
    faster();
    run(){
        string s;
        cin>>s;
        int n=s.size();
        int dp[n][n]={};
        for(int i=0;i<n;i++) dp[i][i]=1;
        for(int i=0;i<n-1;i++) dp[i+1][i]=1;// Khoảng trống cũng là thuận nghịch
        int res=1;
        for(int len=2;len<=n;len++){
            for(int i=0;i<=n-len;i++){
                int j = i+len-1;
                if(s[i]==s[j]) dp[i][j]=dp[i+1][j-1];
                else dp[i][j]=0;
                if(dp[i][j]) res = len;
            }
        }
        cout<<res<<endl;
    }
}