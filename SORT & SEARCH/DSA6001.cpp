#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t; cin>>t; while(t--)
int main(){
    faster();
    run(){
        int n; cin>>n;
        int a[1001];
        for(int i=0;i<n;i++) cin>>a[i];
        sort(a,a+n);
        int l=0,r=n-1;
        while(l<=r){
            if(l==r) cout<<a[l]<<" ";
            else cout<<a[r]<<" "<<a[l]<<" ";
            l++;r--;
        }
        cout<<endl;
    }
}