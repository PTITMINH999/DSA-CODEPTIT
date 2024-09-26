#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t; cin>>t; while(t--)
const int MOD=1e9+7;
int dp[105][50005]={};
void era(){
    for(int i=1;i<=9;i++) dp[1][i]=1;
    for(int i=1;i<=100;i++){
        for(int j=0;j<=9;j++){
            for(int z=j;z<=50000;z++){
                dp[i][z]= (dp[i][z]+dp[i-1][z-j]) % MOD;
            } 
        }
    }
}
int main(){
    faster();
    era();
    run(){
        int n,k;
        cin>>n>>k;
        cout<<dp[n][k]<<endl;
    }
}