#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t; cin>>t; while(t--)
int main(){
    faster();
    int n; cin>>n;
    int a[n];
    for(int &x:a) cin>>x;
    for(int i=0;i<n-1;i++){
        bool ok = false;
        for(int j=0;j<n-i-1;j++){
            if(a[j] > a[j+1]){
                swap(a[j],a[j+1]);
                ok=true;
            }
        }
        if(ok){
            cout<<"Buoc "<<i+1<<": ";
            for(int x:a) cout<<x<<" ";
            cout<<endl;
        }
        else break;
    }
}