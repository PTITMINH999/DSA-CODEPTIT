#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t; cin>>t; while(t--)
#define ll long long
int solve(ll a[],ll l,ll r,ll value){
    ll *it1=lower_bound(a+l,a+r,value);
    ll *it2=upper_bound(a+l,a+r,value);
    return it2-it1;
}
int main(){
    faster();
    run(){
        ll n,k; cin>>n>>k;
        ll a[n];
        for(ll &x:a) cin>>x;
        sort(a,a+n);
        ll cnt=0;
        for(ll i=0;i<n;i++){
            cnt+= solve(a,i+1,n,k-a[i]);
        }
        cout<<cnt<<endl;
    }
}