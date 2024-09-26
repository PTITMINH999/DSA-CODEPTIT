#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t;cin>>t;while(t--)
#define ll long long
int main(){
    faster();
    run(){
        int n;cin>>n;
        int a[n];
        unordered_map<int,int>m;
        for(int &x:a){
            cin>>x;
            m[x]++;
        }
        stack<int>st;
        int res[n];
        for(int i=n-1;i>=0;i--){
            while(st.size() && m[a[st.top()]]<=m[a[i]]){
                st.pop();
            }
            if(st.empty()) res[i]=-1;
            else res[i]=a[st.top()];
            st.push(i);
        }
        for(int x:res) cout<<x<<" ";
        cout<<endl;
    }
}