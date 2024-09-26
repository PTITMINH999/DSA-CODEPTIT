#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t; cin>>t; while(t--)
#define ll long long
int a[1000001];
int b[1000001];
int main(){
    faster();
    run(){
        int n,m; cin>>n>>m;
        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=0;i<m;i++) cin>>b[i];
        int m1=*max_element(a,a+n);
        int m2=*min_element(b,b+n);
        cout<<1ll*m1*m2<<endl;
    }
}