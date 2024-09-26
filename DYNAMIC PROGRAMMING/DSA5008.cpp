#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t; cin>>t; while(t--)
// dp[i]: mảng A có tồn tại tập con có tổng bằng i
int main(){
    faster();
    run(){
        int n,s;cin>>n>>s;
        int a[n];
        for(int &x:a) cin>>x;
        bool dp[s+1]={};
        dp[0]=1;
        for(int i=0;i<n;i++){
            // ko cần xét tập con có tổng < a[i]
            for(int j=s;j>=a[i];j--){
                if(!dp[j]) dp[j]=dp[j-a[i]];
            }
        }
        if(dp[s]) cout<<"YES\n";
        else cout<<"NO\n";
    }
}