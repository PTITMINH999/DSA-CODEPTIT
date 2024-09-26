#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
int main(){
    faster();
    int t,v,e,x,y; 
    cin>>t;
    while(t--){
        cin>>v>>e;
        vector<set<int>> vs(v+1);
        while(e--){
            cin>>x>>y;
            vs[x].insert(y);
            vs[y].insert(x);
        }
        for(int i=1;i<=v;i++){
                cout<<i<<": ";
                if(vs[i].empty()) continue;
                for(auto &c:vs[i]){
                    cout<<c<<" ";
                }
                cout<<endl;
            }
    }
    return 0;
}