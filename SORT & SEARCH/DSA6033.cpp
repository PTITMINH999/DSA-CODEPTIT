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
        int maxi[n];
        maxi[n-1]=a[n-1];
        for(int i=n-2;i>=0;i--){
            if(a[i]>maxi[i+1]){
                maxi[i]=a[i];
            }
            else maxi[i]=maxi[i+1];
        }
        int j=0,ans=0;
        for(int i=0;i<n-1;i++){
            while(j<n && a[i]<maxi[j]) j++;
            ans=max(ans,j-i-1);
        }
        if(ans==0) cout<<-1<<endl;
        else cout<<ans<<endl;
    }
}