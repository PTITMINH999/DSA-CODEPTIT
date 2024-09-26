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
        int l[n],r[n];
        l[0]=r[n-1]=1;
        for(int i=1;i<n;i++){
            if(a[i]>a[i-1]) l[i]=l[i-1]+1;
            else l[i]=1;
        }
        for(int i=n-2;i>=0;i--){
            if(a[i]>a[i+1]) r[i]=r[i+1]+1;
            else r[i]=1;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,l[i]+r[i]-1);
        }
        cout<<ans<<endl;
    }
}