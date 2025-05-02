#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t; cin>>t; while(t--)
#define ll long long
int main(){
    faster();
    int n;
    cin>>n;
    unordered_map<ll,int> mp;
    for(int i=0;i<n;i++){
        ll u,v;
        cin>>u>>v;
        mp[u]++;
        mp[v+1]--;
    }
    int q; cin>>q;
    vector<ll> c(q);
    set<ll> st;
    for(int i=0;i<q;i++){
        cin>>c[i];
        st.insert(c[i]);
    }
    for(auto it:mp){
        st.insert(it.first);
    }
    unordered_map<ll,int> ans;
    ll val = 0;
    for(ll it:st){
        val += mp[it];
        ans[it] = val;
    }
    for(int i=0;i<q;i++){
        cout<<ans[c[i]]<<endl;
    }
}