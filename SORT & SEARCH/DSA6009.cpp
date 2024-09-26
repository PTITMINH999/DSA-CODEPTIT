#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t; cin>>t; while(t--)
#define ll long long
int main(){
    faster();
    run(){
        int n,k; cin>>n>>k;
        int a[n];
        map<int,int> m;
        for(int i=0;i<n;i++){
            cin>>a[i];
            m[a[i]]++;
        }
        ll ans=0;
        for(int i=0;i<n;i++){
            ans+=m[k-a[i]];
            if(a[i]*2==k) ans--;
        }
        cout<<ans/2<<endl;
    }
}