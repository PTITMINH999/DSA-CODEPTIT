#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t; cin>>t; while(t--)
#define ll long long
// dp[i]: số cách con ếch có thể nhảy lên i bước 
int main(){
    faster();
    run(){
        int n;cin>>n;
        ll dp[n+5]={};
        dp[1]=1;
        dp[2]=2;
        dp[3]=4;
        for(int i=4;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
        }
        cout<<dp[n]<<endl;
    }
}