#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t; cin>>t; while(t--)
#define ll long long
int main(){
    faster();
    int n; cin>>n;
    string s; cin>>s;
    ll total = 1LL * n *(n-1)/2;
    ll cnt =1;
    vector<ll> a;
    for(int i=1;i<n;i++){
        if(s[i] == s[i-1]) cnt++;
        else{
            a.push_back(cnt);
            cnt = 1;
        }
    }
    a.push_back(cnt);
    for(int i=1;i<a.size();i++){
        total -= (a[i]+a[i-1]-1);
    }
    cout<<total<<endl;
}