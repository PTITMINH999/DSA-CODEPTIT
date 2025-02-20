#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t; cin>>t; while(t--)
#define ll long long
const ll mod = 1e9+7;
int main(){
    faster();
    run(){
        int n,k;
        cin>>n>>k;
        int dp[100005]={};
        dp[0]=dp[1]=1;
        for(int i=2;i<=n;i++){
            for(int j=1;j<=min(i,k);j++){
                dp[i]=(dp[i]+dp[i-j])%mod;
            }
        }
        cout<<dp[n]<<endl;
    }
}