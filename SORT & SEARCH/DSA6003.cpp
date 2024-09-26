#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t; cin>>t; while(t--)
int main(){
    faster();
    run(){
        int n; cin>>n;
        int a[n];
        for(int i=0;i<n;i++) cin>>a[i];
        int idx,cnt=0;
        for(int i=0;i<n;i++){
            idx=i;
            for(int j=i+1;j<n;j++) if(a[idx] > a[j]) idx=j;
            if(idx!=i) cnt++;
            swap(a[idx],a[i]);
        }
        cout<<cnt<<endl;
    }
}