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
        for(int &x:a) cin>>x;
        stack<int> st;
        int res=INT_MIN,i=0;
        while(i<n){
            if(st.empty() || a[i]>=a[st.top()]){
                st.push(i);
                i++;
            }
            else{
                int idx=st.top();
                st.pop();
                if(st.empty()) res=max(res,i*a[idx]);
                else res=max(res,a[idx]*(i-st.top()-1));
            }
        }
        while(!st.empty()){
            int idx=st.top();
            st.pop();
            if(st.empty()) res=max(res,i*a[idx]);
            else res=max(res,a[idx]*(i-st.top()-1));
        }
        cout<<res<<endl;
    }
}