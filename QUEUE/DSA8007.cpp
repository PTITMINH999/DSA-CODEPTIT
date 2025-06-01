#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t;cin>>t;while(t--)
#define ll long long
ll ans=0;
void check(ll n){
    queue<ll> q;
    q.push(1);
    while(q.front() <= n){
        ll s=q.front();
        q.pop();
        if(s<=n) ans++;
        q.push(s*10);
        q.push(s*10+1);
    }
}
int main(){
    faster();
    run(){
        ll n;cin>>n;
        ans=0;
        check(n);
        cout<<ans<<endl;
    }
}