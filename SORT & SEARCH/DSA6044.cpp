#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t; cin>>t; while(t--)
#define ll long long
int main(){
    faster();
    int n; cin>>n;
    vector<int> a(n),chan,le;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(i%2==0) chan.push_back(a[i]);
        else le.push_back(a[i]); 
    }
    sort(le.begin(),le.end(),greater<>());
    sort(chan.begin(),chan.end());
    int b=0,c=0;
    for(int i=0;i<n;i++){
        if(i%2==0) cout<<chan[c++]<<" ";
        else cout<<le[b++]<<" ";
    }
}
