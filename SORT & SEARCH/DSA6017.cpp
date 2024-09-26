#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t; cin>>t; while(t--)
#define ll long long
int main(){
    faster();
    run(){
        int n,m; cin>>n>>m;
        int x;
        multiset<int> s;
        while(n--){
            cin>>x;
            s.insert(x);
        }
        while(m--){
            cin>>x;
            s.insert(x);
        }
        for(int it:s) cout<<it<<" ";
        cout<<endl;
    }
}