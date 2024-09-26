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
        sort(a,a+n);
        if(a[0]==a[n-1]) cout<<-1<<endl;
        else{
            int idx=1;
            while(a[idx]==a[0]) idx++;
            cout<<a[0]<<" "<<a[idx]<<endl;
        }
    }
}