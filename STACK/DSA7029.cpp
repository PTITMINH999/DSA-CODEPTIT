#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t;cin>>t;cin.ignore();while(t--)
#define ll long long
int main(){
    faster();
    run(){
        string s;cin>>s;
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(s[i]==']'){
                string a;
                while(st.size() && st.top()!='['){
                    a=st.top()+a;
                    st.pop();
                }
                st.pop();// pop :"["
                string num;
                while(st.size() && isdigit(st.top())){
                    num=st.top()+num;
                    st.pop();
                }
                int n=1;
                if(num.size()) n=stoi(num);
                string b;
                for(int j=0;j<n;j++) b+=a;
                for(int j=0;j<b.size();j++){
                    st.push(b[j]);
                }
            }
            else st.push(s[i]);
        }
        string ans;
        while(st.size()){
            ans=st.top()+ans;
            st.pop();
        }
        cout<<ans<<endl;
    }
}