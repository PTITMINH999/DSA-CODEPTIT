#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t; cin>>t; while(t--)
#define ll long long
int main(){
    faster();
    run(){
        int n; cin>>n;
        int a[n];
        unordered_map<int,int> m;
        for(int &x:a){
            cin>>x;
            m[x]++;
        }
        int ok=1;
        for(int i=0;i<n;i++){
            if(m[a[i]]>n/2){
                cout<<a[i]<<endl;
                ok=0;
                break;
            }
        }
        if(ok) cout<<"NO"<<endl;
    }
}