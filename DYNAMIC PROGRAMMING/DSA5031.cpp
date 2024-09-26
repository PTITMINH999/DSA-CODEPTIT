#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t; cin>>t; while(t--)
#define ll long long
// dp[i]: số lượng các số nhỏ hơn i có tổng bình phương = i
int main(){
    faster();
    run(){
        int n;cin>>n;
        int dp[n+1]={};
        for(int i=1;i<=n;i++){
            dp[i]=i;// các số = 1^2+...1^2
            for(int j=1;j*j<=i;j++){
                dp[i]=min(dp[i],dp[i-j*j]+1);
            }
        }
        cout<<dp[n]<<endl;
    }
}
