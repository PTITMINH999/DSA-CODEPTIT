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
        int l[n]; l[0]=a[0];
        for(int i=1;i<n;i++){
            l[i]=max(a[i],l[i-1]);
        }
        int r[n];
        r[n-1]=a[n-1];
        for(int i=n-2;i>=0;i--){
            r[i]=min(a[i],r[i+1]);
        }
        vector<int> ans;
        for(int i=0;i<n-1;i++){
            if(l[i]<=r[i+1]){
                ans.push_back(i+1);
            }
        }
        if(ans.size()==0) cout<<0<<endl<<endl;
        else{
            cout<<ans.size()<<endl;
            for(int i:ans) cout<<i<<" ";
            cout<<endl;
        }
    }
}