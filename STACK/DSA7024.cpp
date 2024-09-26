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
        stack<int>st;
        int i=0,res=0;
        while(i<n){
            if(st.empty() || a[i]>a[st.top()]){
                st.push(i);
                i++;
            }
            else{
                int idx=st.top();
                st.pop();
                if(st.empty()){
                    if(a[idx]<=i) res=max(res,a[idx]);
                }
                else if(a[idx]<=(i-st.top()-1)) res=max(res,a[idx]);
            }
        }
        while(st.size()){
            int idx=st.top();
            st.pop();
            if(st.empty()){
                if(a[idx]<=i) res=max(res,a[idx]);
            }
            else if(a[idx]<=(i-st.top()-1)){
                res=max(res,a[idx]);
            }
        }
        cout<<res<<endl;
    }
}