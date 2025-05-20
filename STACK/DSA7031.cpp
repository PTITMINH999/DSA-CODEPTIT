#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define vi vector<int> 
#define vl vector<ll>
int main(){
    faster();
    int t;cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        stack<ll> st;
        for(int i=n-1;i>=0;i--){
            if(isdigit(a[i].back())) st.push(stoll(a[i]));
            else{
                ll x = st.top();st.pop();
                ll y = st.top();st.pop();
                if(a[i]=="+") st.push(x+y);
                else if(a[i]=="-") st.push(x-y);
                else if(a[i]=="*") st.push(x*y);
                else st.push(x/y);
            }
        }
        cout<<st.top()<<endl;   
    }
}