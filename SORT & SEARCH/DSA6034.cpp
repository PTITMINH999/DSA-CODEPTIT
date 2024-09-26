#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t; cin>>t; while(t--)
#define ll long long
int solve(int a[],int l,int r,int value){
    int *it1=lower_bound(a+l,a+r,value);
    int *it2=upper_bound(a+l,a+r,value);
    return it2-it1;
}
int main(){
    faster();
    run(){
        int n,k; cin>>n>>k;
        int a[n];
        for(int &x:a) cin>>x;
        sort(a,a+n);
        int cnt=0;
        for(int i=0;i<n-1;i++){
            cnt+= solve(a,i+1,n,k-a[i]);
        }
        cout<<cnt<<endl;
    }
}