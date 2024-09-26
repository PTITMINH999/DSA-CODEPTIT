#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t; cin>>t; while(t--)
#define ll long long 
int main(){
    faster();
    run(){
        int n,k; cin>>n>>k;
        ll a[n];
        for(ll &x:a) cin>>x;
        sort(a,a+n);
        ll cnt=0;
        for(int i=0;i<n-2;i++){
            int l=i+1,r=n-1;
            while(l<r){
                ll sum=a[i]+a[l]+a[r];
                if(sum>=k) r--;
                else{
                    cnt+=r-l;
                    l++;
                }
            }
        }
        cout<<cnt<<endl;
    }
}