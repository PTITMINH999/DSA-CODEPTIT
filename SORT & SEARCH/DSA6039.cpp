#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t; cin>>t; while(t--)
#define ll long long
string solve(int a[],int n,unordered_map<int,int>m){
    for(int i=0;i<n;i++){
        if(m[a[i]]>1) return to_string(a[i]);
    }
    return "NO";
}
int main(){
    faster();
    run(){
        int n; cin>>n;
        int  a[n];
        unordered_map<int,int>m;
        for(int i=0;i<n;i++){
            cin>>a[i];
            m[a[i]]++;
        }
        cout<<solve(a,n,m)<<endl;
    }
}