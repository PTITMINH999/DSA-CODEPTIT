#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t; cin>>t; while(t--)
#define ll long long
const ll MOD= 1e9+7;
void nhan(ll a[2][2],ll b[2][2]){
    ll res[2][2];
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            res[i][j]=0;
            for(int k=0;k<2;k++){
                res[i][j]+=a[i][k]*b[k][j]%MOD;
            }
        }
    }
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            a[i][j]=res[i][j];
}
void pow(ll n){
    ll res[2][2]={{1,0},{0,1}};
    ll a[2][2]={{1,1},{1,0}};
    while(n){
        if(n%2==1) nhan(res,a);
        nhan(a,a);
        n/=2;
    }
    cout<<res[0][1]<<endl;
}
int main(){
    faster();
    run(){
        ll n;cin>>n;
        pow(n);
    }
}
