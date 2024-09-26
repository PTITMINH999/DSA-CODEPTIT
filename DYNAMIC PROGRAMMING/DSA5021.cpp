#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t; cin>>t; while(t--)
#define ll long long
int main(){
    faster();
    run(){
        int n;cin>>n;
        pair<int,int> a[n];
        for(pair<int,int> &x:a){
            cin>>x.first>>x.second;
        }
        // sort theo first
        sort(a,a+n);
        vector<int> dp(n,1);
        int res=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(a[i].first > a[j].second) dp[i]=max(dp[i],dp[j]+1);
            }
            res=max(res,dp[i]);
        }
        cout<<res<<endl;
    }
}