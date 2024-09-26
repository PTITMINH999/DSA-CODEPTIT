#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t; cin>>t; while(t--)
int main(){
    faster();
    run(){
        int n,k; cin>>n>>k;
        int a[n];
        for(int &x:a) cin>>x;
        multiset<int> s;
        for(int i=0;i<k;i++){
            s.insert(a[i]);
        }
        cout<<*s.rbegin()<<" ";
        for(int i=k;i<n;i++){
            auto it=s.find(a[i-k]);
            s.erase(it);
            s.insert(a[i]);
            cout<<*s.rbegin()<<" ";
        }
        cout<<endl;
    }
}