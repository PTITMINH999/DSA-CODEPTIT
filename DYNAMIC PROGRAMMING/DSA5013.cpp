#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t; cin>>t; while(t--)
#define ll long long 
/*
d[i]: số cách bước đến bậc i
d[i] có k cách bước:
d[i-1] d[i-2] d[i-3] ....d[i-k]; 
*/
const int mod=1e9+7;
int main(){
    faster();
    run(){
        int n,k; cin>>n>>k;
        int d[n+1]={};
        d[0]=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=k;j++){
                //if(i-j<0) break;
                if(i>=j) d[i]=(d[i]+d[i-j])%mod;
            }
        }
        cout<<d[n]<<endl;
    }
}