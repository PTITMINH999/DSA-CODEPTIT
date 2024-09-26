#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t; cin>>t; while(t--)
int main(){
    faster();
    run(){
        int n; cin>>n;
        int a[n];
        for(int &x:a) cin>>x;
        vector<vector<int>> ans;
        for(int i=0;i<n-1;i++){
            bool ok=1;
            for(int j=0;j<n-i-1;j++){
                if(a[j]>a[j+1]){
                    swap(a[j],a[j+1]);
                    ok=0;
                }
            }
            if(ok) break;
            vector<int> v(n);
            for(int k=0;k<n;k++) v[k]=a[k];
            ans.push_back(v);
        }
        for(int i=ans.size()-1;i>=0;i--){
            cout<<"Buoc "<<i+1<<": ";
            for(int j:ans[i]) cout<<j<<" ";
            cout<<endl;
        }
    }
}