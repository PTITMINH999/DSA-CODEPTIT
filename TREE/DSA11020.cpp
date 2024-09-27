#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t;cin>>t;while(t--)
#define ll long long
int main(){
    faster();
    run(){
        int n; cin>>n;
        bool check=1;
        int a[n];
        for(int &x:a) cin>>x;
        for(int i=1;i<n;i++){
            if(a[i]<=a[i-1]){
                check=0;
                break;
            }
        }
        cout<<check<<endl;
        
    }
}