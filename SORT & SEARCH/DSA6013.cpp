#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t; cin>>t; while(t--)
#define ll long long
int main(){
    faster();
    run(){
        int n,x; cin>>n>>x;
        int a[n];
        for(int &i:a) cin>>i;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(a[i]==x) cnt++;
        }
        if(cnt==0) cout<<"-1"<<endl;
        else cout<<cnt<<endl;
    }
}