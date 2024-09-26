#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t; cin>>t; while(t--)
#define ll long long
int main(){
    faster();
    run(){
        int n;cin>>n;
        ll a[n],b[n-1];
        map<ll,int> m;
        for(int i=0;i<n;i++){
            cin>>a[i];
            m[a[i]]++;
        }
        for(int i=0;i<n-1;i++){
            cin>>b[i];
            m[b[i]]++;
        }
        for(int i=0;i<n;i++){
            if(m[a[i]]==1){
                cout<<i+1<<endl;
                break;
            }
        }
    }
}