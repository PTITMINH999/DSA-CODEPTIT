#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t; cin>>t; while(t--)
int main(){
    faster();
    int n;cin>>n;
    vector<int> a(n);
    for(int &x:a) cin>>x;
    vector<int> dp(n,1);
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(a[i]>a[j]){
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
    }
    cout<<*max_element(dp.begin(),dp.end());
}