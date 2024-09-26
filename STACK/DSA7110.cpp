#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t;cin>>t;cin.ignore();while(t--)
#define ll long long
string solve(string s){
    stack<char> st;
    for(char c:s){
        if(st.empty() || c=='(' || c=='[' || c=='{') st.push(c);
        else{
            if(c==')'){
                if(st.top()=='(') st.pop();
                else return "NO";
            }
            if(c==']'){
                if(st.top()=='[') st.pop();
                else return "NO";
            }
            if(c=='}'){
                if(st.top()=='{') st.pop();
                else return "NO";
            }
        }
    }
    if(st.size()) return "NO";
    return "YES";
}
int main(){
    faster();
    run(){
        string s;cin>>s;
        cout<<solve(s)<<endl;
    }
}