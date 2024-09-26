#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t; cin>>t; while(t--)
#define ll long long
// dp[i][j]: số cách di chuyển từ -->[i,j]
int main(){
    faster();
    run(){
        int n,m; 
        cin>>n>>m;
        vector<vector<int>>dp(n+5, vector<int>(m+5,1));
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                dp[i][j]=dp[i+1][j]+dp[i][j+1];
            }
        }
        cout<<dp[0][0]<<endl;
    }
}