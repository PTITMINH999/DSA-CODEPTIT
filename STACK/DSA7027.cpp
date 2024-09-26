#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t;cin>>t;cin.ignore();while(t--)
#define ll long long
int main(){
    faster();
    run(){
        int n;cin>>n;
        int a[n];
        for(int &x:a) cin>>x;
        stack<int> st;
        int res[n];
        for(int i=n-1;i>=0;i--){
            while(st.size() && st.top()<=a[i]){
                st.pop();
            }
            if(st.empty()) res[i]=-1;
            else res[i]=st.top();
            st.push(a[i]);
        }
        for(int c:res) cout<<c<<" ";
        cout<<endl;
    }
}