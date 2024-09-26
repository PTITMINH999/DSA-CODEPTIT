#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t; cin>>t; while(t--)
#define ll long long
int main(){
    faster();
    run(){
        ll n,k; cin>>n>>k;
        ll a[n];
        for(int i=0;i<n;i++) cin>>a[i];
        ll sum=0;
        int l=0,r=0;
        bool ok=0;
        while(r<n){
            sum+=a[r];
            while(l<r && sum>k){
                sum-=a[l];
                l++;
            }
            if(sum==k){
                ok=1;
                break;
            }
            r++;
        }
        if(ok) cout<<"YES\n";
        else cout<<"NO\n";
    }
}