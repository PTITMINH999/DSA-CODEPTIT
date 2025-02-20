#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t; cin>>t; while(t--)
#define ll long long
const int M = 15;
int n,dp[M][1<<M],cost[M][M];
int tsp(int mask,int cur){
    if(mask == (1<<n)-1){
        return 0;
    }
    if(dp[cur][mask]!=-1){
        return dp[cur][mask];
    }
    int ans = INT_MAX;
    for(int i=0;i<n;i++){
        if((mask & (1<<i))==0){
            ans = min(ans,cost[cur][i]+tsp(mask|(1<<i),i));
        }
    }
    return dp[cur][mask]=ans;
}
int main(){
    faster();
    run(){
        cin>>n;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>cost[i][j];
            }
        }
        memset(dp,-1,sizeof (dp));
        int ans = INT_MAX;
        for(int i=0;i<n;i++){
            ans=min(ans,tsp(1<<i,i));
        }
        cout<<ans<<endl;
    }
}