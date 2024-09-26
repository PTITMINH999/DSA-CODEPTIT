#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t;cin>>t;while(t--)
#define ll long long
int degree(char c){
    if(c=='+' || c=='-') return 1;
    if(c=='*' || c=='/') return 2;
    if(c=='^' || c=='%') return 3;
    return 0;
}
int main(){
    faster();
    run(){
        string s; cin>>s;
        string res="";
        stack<char>st;
        for(int i=0;i<s.size();i++){
            if(isalpha(s[i])) res+=s[i];
            else if(s[i]=='(') st.push(s[i]);
            else if(s[i]==')'){
                while(st.size() && st.top()!='('){
                    res+=st.top();
                    st.pop();
                }
                st.pop();
            }
            else if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'||s[i]=='^'){
                while(st.size() && degree(st.top())>=degree(s[i])){
                    res+=st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
        }
        while(st.size()){
            if(st.top()!='(') res+=st.top();
            st.pop();
        }
        cout<<res<<endl;
    }
}