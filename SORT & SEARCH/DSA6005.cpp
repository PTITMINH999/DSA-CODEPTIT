#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t; cin>>t; while(t--)
int main(){
    faster();
    run(){
        int n,m;
        cin>>n>>m;
        int a[n],b[m];
        set<int> s,x,y;
        for(int i=0;i<n;i++){
            cin>>a[i];
            s.insert(a[i]);
            x.insert(a[i]);
        }
        for(int i=0;i<m;i++){
            cin>>b[i];
            s.insert(b[i]);
            y.insert(b[i]);
        }
        for(int c:s) cout<<c<<" ";
        cout<<endl;
        for(int c:x){
            if(y.find(c)!=y.end()){
                cout<<c<<" ";
            }
        }
        cout<<endl;
    }
}