#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t; cin>>t; while(t--)
int a[100001];
int n,x;
bool cmp(pair<int,int> a,pair<int,int> b){
    if(abs(x-a.first) != abs(x-b.first)){
        return abs(x-a.first)<abs(x-b.first);
    }
    return a.second<b.second;
}
int main(){
    faster();
    run(){
        cin>>n>>x;
        vector<pair<int,int>> v(n);
        for(int i=0;i<n;i++){
            cin>>v[i].first;
            v[i].second=i;
        }
        sort(v.begin(),v.end(),cmp);
        for(int i=0;i<n;i++){
            cout<<v[i].first<<" ";
        }
        cout<<endl;
    }
}