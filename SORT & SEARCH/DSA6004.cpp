#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t; cin>>t; while(t--)
int main(){
    faster();
    run(){
        int n,m; cin>>n>>m;
        int a[n],b[m];
        for(int &x:a) cin>>x;
        for(int &x:b) cin>>x;
        int i=0,j=0;    
        vector<int> v,s;// v:giao, s:hợp
        while(i<n && j<m){
            if(a[i]<b[j]){
                s.push_back(a[i]);
                i++;
            }
            else if(b[j]<a[i]){
                s.push_back(b[j]);
                j++;
            }
            else{
                s.push_back(a[i]);
                v.push_back(a[i]);
                i++;j++;
            }
        }
        while(i<n)s.push_back(a[i++]);
        while(j<m) s.push_back(b[j++]);
        for(int i:s) cout<<i<<" ";
        cout<<endl;
        for(int i:v) cout<<i<<" ";
        cout<<endl;
    }
}