#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t; cin>>t; while(t--)
#define ll long long
const int mod =1e9+7;
// dp[i]: số cách lấy các phần tử có tổng = i
int main(){
    faster();
    run(){
        int n,k;cin>>n>>k;
        int a[n];
        for(int i=0;i<n;i++) cin>>a[i];
        int dp[k+5]={};
        dp[0]=1;
        for(int i=1;i<=k;i++){
            for(int j=0;j<n;j++){
                if(i>=a[j]) dp[i]=(dp[i]%mod + dp[i-a[j]]%mod)%mod;
            }
        }
        cout<<dp[k]<<endl;
    }
}