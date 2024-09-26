#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t; cin>>t; while(t--)
#define ll long long
string solve(int a[],int n,int &k){
    int l,r;
    for(int i=0;i<n;i++){
        l=i+1;
        r=n-1;
        while(l<r){
            if(a[i]+a[l]+a[r]==k) return "YES";
            if(a[i]+a[l]+a[r]>k) r--;
            else l++;
        }
    }
    return "NO";
}
int main(){
    faster();
    run(){
        int n,k; cin>>n>>k;
        int a[n];
        for(int &x:a) cin>>x;
        sort(a,a+n);
        cout<<solve(a,n,k)<<endl;
    }
}