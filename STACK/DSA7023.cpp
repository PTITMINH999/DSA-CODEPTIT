#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t;cin>>t;cin.ignore();while(t--)
#define ll long long
int main(){
    faster();
    run(){
        string s;
        getline(cin,s);
        stack<string>st;
        stringstream ss(s);
        while(ss>>s) st.push(s);
        while(!st.empty()){
            cout<<st.top()<<" ";
            st.pop();
        }
        cout<<endl;
    }    
}