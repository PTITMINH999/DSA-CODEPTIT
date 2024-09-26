#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t; cin>>t; while(t--)
int main(){
    faster();
    run(){
        int n;cin>>n;
        int a[n],dp[n];
        for(int i=0;i<n;i++) cin>>a[i];
        // có thể lấy môn trong 2 a[0],a[1] vì cạnh nhau nên ko chọn đc cả 2
        dp[0]=a[0];
        dp[1]=max(a[0],a[1]);
        for(int i=2;i<n;i++){
            dp[i]=max(dp[i-1],dp[i-2]+a[i]);
        }
        cout<<dp[n-1]<<endl;
    }
}