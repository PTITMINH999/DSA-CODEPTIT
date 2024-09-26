#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t; cin>>t; while(t--)
#define ll long long
int main(){
    faster();
    run(){
        int n; cin>>n;
        int a[n];
        for(int &x:a) cin>>x;
        int l[n]; l[0]=a[0];
        for(int i=1;i<n;i++) 
            l[i]=l[i-1]+a[i];
        int r[n]; r[n-1]=a[n-1];
        for(int i=n-2;i>=0;i--) 
            r[i]=r[i+1]+a[i];
        int  ok=1;
        for(int i=0;i<n;i++){
            if(l[i]==r[i]){
                cout<<i+1<<endl;
                ok=0;
                break;
            }
        }
        if(ok) cout<<-1<<endl;
    }
}