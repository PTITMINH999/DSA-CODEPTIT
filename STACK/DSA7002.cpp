#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t;cin>>t;while(t--)
#define ll long long
int main(){
    faster();
    int q;cin>>q;
    int n;
    string s;
    stack<int>st;
    while(q--){
        cin>>s;
        if(s=="PUSH"){
            cin>>n;
            st.push(n);
        }
        else if(s=="POP" && !st.empty()){
            st.pop();
        }
        else if(s=="PRINT"){
            if(!st.empty()) cout<<st.top()<<endl;
            else cout<<"NONE"<<endl;
        }
    }
}