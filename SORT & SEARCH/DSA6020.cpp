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
        set<int> s;
        for(int i=0;i<n;i++){
            cin>>a[i];
            s.insert(a[i]);
        }
        if(s.count(x)==0) cout<<-1<<endl;
        else cout<<1<<endl;
    }
}