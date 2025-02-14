#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t; cin>>t; while(t--)
#define ll long long
int main(){
    faster();
    run(){
        int n1,n2,n3;
        cin>>n1>>n2>>n3;
        ll a[n1],b[n2],c[n3];
        for(ll &x:a) cin>>x;
        for(ll &x:b) cin>>x;
        for(ll  &x:c) cin>>x;
        int l=0,r=0,q=0;
        vector<ll> res;
        while(l<n1 && r<n2 && q<n3){
            if(a[l]==b[r] && a[l]==c[q]){
               res.push_back(a[l]);
                l++,r++,q++;
            }
            else if(a[l] < b[r]){
                l++;
            }
            else if(b[r] < c[q]){
                r++;
            }
            else q++;
        }
        if(res.empty()) cout<<-1<<endl;
        else{
            for(ll r:res){
                cout<<r<<" ";
            }
            cout<<'\n';
        }
    }   
}