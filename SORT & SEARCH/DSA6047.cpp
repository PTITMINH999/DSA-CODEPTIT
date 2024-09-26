#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t; cin>>t; while(t--)
#define ll long long
ll a[5005],n;
bool check(){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            ll ab= a[i]*a[i]+a[j]*a[j];
            ll c=sqrt(ab);
            if(ab==c*c){
                ll *it =lower_bound(a+j,a+n,c);
                if(it!= a+n && *it==c)
                    return 1;
            }
        }
    }
    return 0;
}
int main(){
    faster();
    run(){
        cin>>n;
        for(int i=0;i<n;i++) cin>>a[i];
        sort(a,a+n);
        if(check()) cout<<"YES\n";
        else cout<<"NO\n";
    }
}