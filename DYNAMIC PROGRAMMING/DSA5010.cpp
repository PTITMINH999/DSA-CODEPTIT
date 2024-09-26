#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t; cin>>t; while(t--)
// dp[i][j]: độ dài dãy con xét đến vị trí thứ i sao cho tổng của nó %k bằng j;
int main(){
    faster();
    run(){
        int n,k; cin>>n>>k;
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
            a[i]%=k;
        }
        int dp[n][k];
        for(int i=0;i<n;i++){
            for(int j=0;j<k;j++){
                dp[i][j]=INT_MIN;
            }
        }
        dp[0][a[0]]=1;
        for(int i=1;i<n;i++){
            for(int j=0;j<k;j++){
                dp[i][j]=max(dp[i-1][j],dp[i-1][(j+k-a[i])%k]+1);
            }
        }
        cout<<dp[n-1][0]<<endl;
    }
}