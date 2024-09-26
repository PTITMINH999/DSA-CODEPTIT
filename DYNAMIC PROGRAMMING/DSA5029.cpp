#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t; cin>>t; while(t--)
#define ll long long
/*
    dp[i]: số cách giải mã khi bản tin kết thúc tại s[i];
    1. Dùng 1 kí tự => dp[i] += dp[i-1];
    2. Dùng 2 kí tự => dp[i] += dp[i-2];
*/
int main(){
    faster();
    run(){
        string s;cin>>s;
        int n=s.size();
        if(s[0]=='0'){
            cout<<0<<endl;
            continue;
        }
        int dp[n+1]={};
        dp[0]=dp[1]=1;
        for(int i=2;i<=n;i++){
            if(s[i-1]>'0') dp[i]+=dp[i-1];
            if(s[i-2]=='1' || s[i-2]=='2' && s[i]<='6') dp[i]+=dp[i-2];
        }
        cout<<dp[n]<<endl;
    }
}