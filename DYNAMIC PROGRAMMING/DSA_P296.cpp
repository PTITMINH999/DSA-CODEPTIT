#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t; cin>>t; while(t--)
#define ll long long
int main(){
    faster();
    int n,q;
    cin>>n>>q;
    int a[n];
    for(int &x:a) cin>>x;
    vector<int> dp(n+1,0);
    for(int i=1;i<=n;i++){
        dp[i] = max(dp[i-1],dp[i-1]+a[i-1]);
    }
    while(q--){
        int l,r;
        cin>>l>>r;
        cout<<dp[r]-dp[l-1]<<endl;
    }
}