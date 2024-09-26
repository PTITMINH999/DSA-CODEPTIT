#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t; cin>>t; while(t--)
#define ll long long
void merge(int a[],int l,int m,int r){
    vector<int> x(a+l,a+m+1);
    vector<int> y(a+m+1,a+r+1);
    int i=0,j=0;
    while(i<x.size() && j<y.size()){
        if(x[i]<=y[j]){
            a[l]=x[i]; l++;i++;
        }
        else{
            a[l]=y[j];
            l++;j++;
        }
    }
    while(i<x.size()){
        a[l]=x[i];
        l++;i++;
    }
    while(j<y.size()){
        a[l]=y[j];l++;j++;
    }
}
void mergesort(int a[],int l,int r){
    if(l>=r) return;
    int m=(l+r)/2;
    mergesort(a,l,m);
    mergesort(a,m+1,r);
    merge(a,l,m,r);
}
int main(){
    faster();
    run(){
        int n; cin>>n;
        int a[n];
        for(int i=0;i<n;i++) cin>>a[i];
        mergesort(a,0,n-1);
        for(int x:a) cout<<x<<" ";
        cout<<endl;
    }
}