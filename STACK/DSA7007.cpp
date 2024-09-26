#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t;cin>>t;while(t--)
#define ll long long
string test(string s){
    stack<char>st;
    for(int i=0;i<s.size();i++){
        if(s[i]==')'){
            string tmp;
            while(st.size() && st.top()!='('){
                tmp=st.top()+tmp;
                st.pop();
            }
            st.pop();
            char c;
            if(st.size()) c=st.top();
            for(int j=0;j<tmp.size();j++){
                if(c=='-' && st.size()){
                    if(tmp[j]=='-') st.push('+');
                    else if(tmp[j]=='+') st.push('-');
                    else st.push(tmp[j]);
                }
                else st.push(tmp[j]);
            }
        }
        else st.push(s[i]);
    }
    string res;
    while(st.size()){
        res=st.top()+res;
        st.pop();
    }
    return res;
}
int main(){
    faster();
    run(){
        string a,b;cin>>a>>b;
        if(test(a)==test(b)) cout<<"YES\n";
        else cout<<"NO\n";
    }
}