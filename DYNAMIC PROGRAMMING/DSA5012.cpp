#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t; cin>>t; while(t--)
#define ll long long 
#define MOD (ll) 1000000007
ll c[1001][1001]={};
void era(){
    for(int i=1;i<=1000;i++) c[0][i]=1;
    c[1][1]=1;
    for(int i=2;i<=1000;i++){
        for(int j=1;j<=i;j++){
            c[j][i]=(c[j-1][i-1] + c[j][i-1])%MOD;
        }
    }
}
int main(){
    faster();
    era();
    // ll c[1001][1001]={};
    // for(int i=1;i<=1000;i++) c[0][i]=1;
    // c[1][1]=1;
    // for(int i=2;i<=1000;i++){
    //     for(int j=1;j<=i;j++){
    //         c[j][i]=(c[j-1][i-1] + c[j][i-1])%MOD;
    //     }
    // }
    int t;cin>>t;
    while(t--){
        int n,k;cin>>n>>k;
        cout<<c[k][n]<<endl;
    }
}