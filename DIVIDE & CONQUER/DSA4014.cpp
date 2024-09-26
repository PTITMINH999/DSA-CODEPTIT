#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t; cin>>t; while(t--)
#define ll long long
int merge(ll a[],int l,int m,int r){
    vector<int> x(a+l,a+m+1);
    vector<int> y(a+m+1,a+r+1);
    int i=0,j=0;
    int cnt=0;
    while(i< x.size() && j<y.size()){
        if(x[i]<=y[j]){
            a[l]=x[i];
            l++;i++;
        }
        else{
            cnt+=x.size()-i;
            a[l]=y[j];
            l++;j++;
        }
    }
    while(i<x.size()){
        a[l]=x[i];
        l++;i++;
    }
    while(j<y.size()){
        a[l]=y[j];
        l++;j++;
    }
    return cnt;
}
int mergesort(ll a[],int l,int r){
    int res=0;
    if(l<r){
        int m=(l+r)/2;
        res+=mergesort(a,l,m);
        res+=mergesort(a,m+1,r);
        res+=merge(a,l,m,r);
    }
    return res;
}
int main(){
    faster();
    run(){
        int n; cin>>n;
        ll a[n];
        for(ll &x:a) cin>>x;
        cout<<mergesort(a,0,n-1)<<endl;
    }
}