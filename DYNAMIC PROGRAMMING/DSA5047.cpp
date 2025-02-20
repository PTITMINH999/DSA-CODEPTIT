#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t; cin>>t; while(t--)
#define ll long long
#define bit(n,i) ((n>>i) & 1)
const int maxn = 10001;
const int N = 5;
int n, a[4][maxn], dp[maxn][16],d[16];
int main(){
    faster();
    run(){
        int ans=INT_MIN,res=INT_MIN;
        cin>>n;
        for(int i=0;i<4;i++){
            for(int j=1;j<=n;j++){
                cin>>a[i][j];
                res=max(res,a[i][j]);
            }
        }
        for(int i=0;i<15;i++){
            bool ok =1;
            for(int j=0;j<3;j++){
                if(bit(i,j) && bit(i,j+1)) ok =0;
            }
            d[i] = ok;
        }
        for(int i=1;i<=n;i++){
            for(int mask = 0;mask<16;mask++){
                dp[i][mask]=INT_MIN;
                if(d[mask]){
                    int sum = 0;
                    for(int j= 0;j<4;j++){
                        if(bit(mask,j)) sum+=a[j][i];
                    }
                    for(int pre = 0;pre<16; pre++){
                        if(d[pre] && ((pre & mask) == 0)){
                            dp[i][mask] = max(dp[i][mask],dp[i-1][pre] + sum);
                        }
                    }
                    ans = max(ans,dp[i][mask]);
                }
            }
        }
        if(ans==0){
            cout<<res<<endl;
        }
        else cout<<ans<<endl;
    }
}