#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define run() int t;cin>>t;while(t--)
#define ll long long
#define vi vector<int> 
#define vl vector<ll>
int main(){
    faster();
    run(){
        int n;
        cin>>n;
        vector<string> a(n);
        for(int i=0;i<n;i++) cin>>a[i];
        stack<ll> st;
        for(int i=0;i<n;i++){
            if(isdigit(a[i].back())){
                st.push(stoll(a[i]));
            }
            else{
                ll x = st.top();st.pop();
                ll y = st.top();st.pop();
                if(a[i]=="+") st.push(y+x);
                else if(a[i]=="-") st.push(y-x);
                else if(a[i]=="*") st.push(y*x);
                else st.push(y/x);
            }
        }
        cout<<st.top()<<endl;;
    }
}