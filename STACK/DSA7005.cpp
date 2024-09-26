#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t;cin>>t;while(t--)
#define ll long long
// a-(b-c-(d+e))-f
string solve(string s){
    stack<char> st;
    for(int i=0;i<s.length();i++){
        if(s[i]==')'){
            string tmp;
            //tmp= d+e
            while(st.size() && st.top()!='('){
                tmp=st.top()+tmp;
                st.pop();
            }
            st.pop();// pop'('
            char c;
            if(st.size()) c=st.top();//c='-'
            // đổi dấu 
            for(int j=0;j<tmp.length();j++){
                if(c=='-' && st.size()){
                    if(tmp[j]=='-') st.push('+');
                    else if(tmp[j]=='+') st.push('-');
                    else st.push(tmp[j]);
                }
                else{
                    st.push(tmp[j]);
                }
            }
        }
        else st.push(s[i]);
    }
    string res;
    while(!st.empty()){
        res=st.top()+res;
        st.pop();
    }
    return res;
}
int main(){
    faster();
    run(){
        string s;cin>>s;
        cout<<solve(s)<<endl;
    }
}