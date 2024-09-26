#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t;cin>>t;while(t--)
#define ll long long
string check(string s){
    stack<char>st;
    for(char c:s){
        if(c==')'){
            bool ok=1;
            while(st.top()!='('){
                char tmp=st.top();
                if(tmp=='+' || tmp=='-' || tmp=='*' || tmp=='/') ok=0;
                st.pop();
            }
            if(ok) return "Yes";
            st.pop(); // pop '('
        }
        else st.push(c);
    }
    return "No";
}
int main(){
    faster();
    run(){
        string s; cin>>s;
        cout<<check(s)<<endl;
    }
}