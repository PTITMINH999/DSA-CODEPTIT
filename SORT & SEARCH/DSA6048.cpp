#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t; cin>>t; while(t--)
#define ll long long
int check(int a[],int n){
    for(int i=0;i<n-1;i++){
        if(a[i]>a[i+1]){
            return i+1;
        }
    }
    return 0;
}
int main(){
    faster();
    run(){
        int n; cin>>n;
        int a[n];
        for(int &x:a) cin>>x;
        cout<<check(a,n)<<endl;
    }
}