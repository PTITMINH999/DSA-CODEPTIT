#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t; cin>>t; while(t--)
#define ll long long
/*
dp[i]: thời gian nhỏ nhất tại i kí tự giống nhau
*/
int main(){
    faster();
    run(){
        int n,insert,del,copy;
        cin>>n>>insert>>del>>copy;
        int dp[n+1];
        dp[1]=insert;
        for(int i=2;i<=n;i++){
            dp[i]=dp[i-1]+insert;
            if(i%2==1) dp[i]=min(dp[i],dp[i/2+1]+copy+del);
            else dp[i]=min(dp[i],dp[i/2]+copy);
        }
        cout<<dp[n]<<endl;
    }
}