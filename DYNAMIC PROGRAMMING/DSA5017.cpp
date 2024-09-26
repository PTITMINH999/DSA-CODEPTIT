#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t; cin>>t; while(t--)
#define ll long long
int main(){
    faster();
    run(){
        int n;cin>>n;
        int a[n];
        for(int &x:a) cin>>x;
        vector<int> dpL(n,0), dpR(n,0);
        for(int i=0;i<n;i++){
            dpL[i]=a[i];
            dpR[i]=a[i];
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(a[i] > a[j]) dpL[i]=max(dpL[i],dpL[j]+a[i]);
            }
        }
        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>i;j--){
                if(a[i] > a[j]) dpR[i]=max(dpR[i],dpR[j]+a[i]);
            }
        }
        int ans=-1;
        for(int i=0;i<n;i++){
            ans=max(ans,dpL[i]+dpR[i]-a[i]);
        }
        cout<<ans<<endl;
    }
}