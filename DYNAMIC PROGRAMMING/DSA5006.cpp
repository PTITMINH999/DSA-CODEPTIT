#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t; cin>>t; while(t--)
int main(){
    faster();
    run(){
        int n;cin>>n;
        int a[n],dp[n];
        for(int &x:a) cin>>x;
        for(int i=0;i<n;i++){
            dp[i]=a[i];
            for(int j=0;j<i;j++){
                if(a[i]>a[j]) dp[i]=max(dp[j],dp[j]+a[i]);
            }
        }
        cout<<*max_element(dp,dp+n)<<endl;
    }
}