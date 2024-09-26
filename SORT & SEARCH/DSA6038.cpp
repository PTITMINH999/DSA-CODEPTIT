#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t; cin>>t; while(t--)
#define ll long long
int merge(int a[],int l,int m,int r){
    vector<int> x(a+l,a+m+1);
    vector<int> y(a+m+1,a+r+1);
    int i=0,j=0;
    int cnt=0;
    while(i<x.size() && j<y.size()){
        if(x[i]<=y[j]){
            a[l]=x[i];
            l++;i++;
        }
        else{
            cnt+=x.size()-i;
            a[l]=y[j];l++;j++;
        }
    }
    while(i<x.size()) a[l++]=x[i++];
    while(j<y.size()) a[l++]=y[j++];
    return cnt;
}
int mergesort(int a[],int l,int r){
    int dem=0;
    if(l<r){
        int m=(l+r)/2;
        dem+=mergesort(a,l,m);
        dem+=mergesort(a,m+1,r);
        dem+=merge(a,l,m,r);
    }
    return dem;
}
int main(){
    faster();
    int n,m=0; cin>>n;
    int a[100000];
    int b[100000];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        if(a[i]%2==0){
            b[m++]=a[i];
        }
    }
    int ans= mergesort(b,0,m-1);
    int cnt=0;
    a[n]=1;
    for(int i=1;i<=n;i++){
        if(a[i]%2==0 && a[i-1]%2==0) cnt++;
        else if(a[i]%2==1 && a[i-1]%2==0){
            ans-=mergesort(a,i-cnt-1,i-1);
            cnt=0;
        }
    }
    cout<<ans;
}