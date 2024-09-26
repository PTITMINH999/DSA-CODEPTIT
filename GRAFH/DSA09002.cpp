#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
int main(){
    faster();
    int n; cin>>n;
    vector<vector<int>> v(n+1);
    cin.ignore();
    for(int i=1;i<=n;i++){
        string s,num;
        getline(cin,s);
        stringstream ss(s);
        while(ss>>num){
            v[i].push_back(stoi(num));
        }
    }
    for(int i=1;i<=n;i++){
        sort(v[i].begin(),v[i].end());
        for(int &x:v[i]){
            if(i<x) cout<<i<<" "<<x<<endl;
        }
    }
}