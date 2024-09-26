#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t; cin>>t; while(t--)
#define ll long long
int main(){
    faster();
    run(){
        int n; cin>>n;
        int l=INT_MAX, r=INT_MIN;
        bool a[1001]={0};
        for(int i=0;i<n;i++){
            int x; cin>>x;
            l=min(l,x);
            r=max(r,x);
            a[x]=1;
        }
        int cnt=0;
        for(int i=l;i<=r;i++){
            if(a[i]==0) cnt++;
        }
        cout<<cnt<<endl;
    }
}