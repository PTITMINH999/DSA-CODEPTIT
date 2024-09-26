#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t; cin>>t; while(t--)
#define ll long long
int main(){
    faster();
    run(){
        int n;cin>>n;
        double a[n],b[n];
        for(int i=0;i<n;i++) cin>>a[i]>>b[i];
        vector<int> dp(n,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(a[i]>a[j] && b[i]<b[j]) dp[i]=max(dp[i],dp[j]+1);
            }
        }
        cout<<*max_element(dp.begin(),dp.end())<<endl;
    }
}