#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t; cin>>t; while(t--)
#define ll long long 
const ll mod=1e9+7;
int main(){
    faster();
    run(){
        int n,k; cin>>n>>k;
        if(k>n) cout<<0<<endl;
        else if(k==0) cout<<1<<endl;
        else{
            ll res=1;
            for(int i=n;i>=n-k+1;i--){
                res=(res*i)%mod;
            }
            cout<<res<<endl;
        }
    }
}