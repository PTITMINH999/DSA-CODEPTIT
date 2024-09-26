#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t; cin>>t; while(t--)
#define ll long long
/*
    dp[i][j]: số các số có chữ số tăng dần có i chữ số và kết thúc bằng j
*/
const ll mod=1e9+7;
ll dp[101][10];
void era(){
    for(int i=0;i<=9;i++) dp[1][i]=1;
    for(int i=2;i<=100;i++){
        for(int j=0;j<=9;j++){
            for(int k=0;k<=j;k++){
                    dp[i][j]=(dp[i][j]+dp[i-1][k])%mod;
            }
        }
    }
}
int main(){
    faster();
    era();
    run(){
        int n;cin>>n;
        ll cnt=0;
        for(int i=0;i<=9;i++) cnt=(cnt+dp[n][i])%mod;
        cout<<cnt<<endl;
    }
}