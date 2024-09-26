#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t; cin>>t; while(t--)
int main(){
    faster();
    int n; cin>>n;
    int a[n];
    for(int &x:a) cin>>x;
    vector<vector<int>> ans;
    for(int i=0;i<n-1;i++){
        int mini=i;
        for(int j=i+1;j<n;j++){
            if(a[j]<a[mini]) mini=j;
        }
        swap(a[i],a[mini]);
        vector<int> v;
        for(int k=0;k<n;k++) v.push_back(a[k]);
        ans.push_back(v);
    }
    for(int i=ans.size()-1;i>=0;i--){
        cout<<"Buoc "<<i+1<<": ";
        for(int j:ans[i]) cout<<j<<" ";
        cout<<endl;
    }
}