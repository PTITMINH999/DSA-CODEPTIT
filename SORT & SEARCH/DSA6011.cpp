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
        for(int i=0;i<n;i++) cin>>a[i];
        int ans=INT_MAX;
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(abs(a[i]+a[j])<mini){
                    mini=abs(a[i]+a[j]);
                    ans=a[i]+a[j];
                }
            }
        }
        cout<<ans<<endl;
    }
}