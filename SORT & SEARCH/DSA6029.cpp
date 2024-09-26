#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t; cin>>t; while(t--)
int main(){
    faster();
    int n; cin>>n;
    set<int>s;
    vector<vector<int>> ans;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        s.insert(x);
        vector<int>v;
        for(int j:s) v.push_back(j);
        ans.push_back(v);
    }
    for(int i=ans.size()-1;i>=0;i--){
        cout<<"Buoc "<<i<<": ";
        for(int j:ans[i]) cout<<j<<" ";
        cout<<endl;
    }
}