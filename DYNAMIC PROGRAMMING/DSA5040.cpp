#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t; cin>>t; while(t--)
#define ll long long
int main(){
    faster();
    run(){
        int n;
        cin>>n;
        int a[n];
        for(int &x:a) cin>>x;
        int inc[n],dec[n];
        inc[0]=dec[n-1]=1;
        for(int i=1;i<n;i++){
            if(a[i]>a[i-1]) inc[i]=inc[i-1]+1;
            else inc[i]=1;
        }
        for(int i=n-2;i>=0;i--){
            if(a[i]>a[i+1]) dec[i]=dec[i+1]+1;
            else dec[i]=1;
        }
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            ans=max(ans,inc[i]+dec[i]-1);
        }
        cout<<ans<<endl;
    }
}