#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
int main(){
    faster();
    int t; cin>>t;
    while(t--){
        int v,e;
        cin>>v>>e;
        vector<set<int>> a(v+1);
        while(e--){
            int x,y;
            cin>>x>>y;
            a[x].insert(y);
        }
        for(int i=1;i<=v;i++){
            cout<<i<<": ";
            for(auto c:a[i]) cout<<c<<" ";
            cout<<endl;
        }
    }
}