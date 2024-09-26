#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t; cin>>t; while(t--)
int main(){
    faster();
    run(){
        int n; cin>>n;
        int a[n];
        int b[3]={0};
        for(int i=0;i<n;i++){
            cin>>a[i];
            b[a[i]]++;
        }
        for(int i=0;i<=2;i++){
            for(int j=0;j<b[i];j++){
                cout<<i<<" ";
            }
        }
        cout<<endl;
    }
}