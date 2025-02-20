#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t; cin>>t; while(t--)
#define ll long long
const int M = 20;
int n,a[M][M], dp[M][1<<M];
int Try(int i,int mask){
    if(i>=n) return 0;
    if(dp[i][mask] != -1){
        return dp[i][mask];
    }
    int rowStatus = 1<<(n-1);
    int ans = 0;
    for(int j=0;j<n;j++){
        if((mask & rowStatus)==0){
            int cur = mask | rowStatus;
            ans=max(ans, a[i][j] + Try(i+1,cur));
        }
        rowStatus = rowStatus>>1;
    }
    return dp[i][mask] = ans;
}
int main(){
    faster();
    run(){
        cin>>n;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>a[i][j];
            }
        }
        memset(dp,-1,sizeof dp);
        cout<<Try(0,0)<<endl;
    }
}