#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t; cin>>t; while(t--)
#define ll long long
map<int,int> m;
int a[100001],n;
bool cmp(int a,int b){
    if(m[a]!=m[b]) return m[a]>m[b];
    return a<b;
}
int main(){
    faster();
    run(){
        cin>>n;
        m.clear();
        for(int i=0;i<n;i++){
            cin>>a[i];
            m[a[i]]++;
        }
        sort(a,a+n,cmp);
        for(int i=0;i<n;i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
}