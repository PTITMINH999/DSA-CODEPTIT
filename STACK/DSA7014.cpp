#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t;cin>>t;while(t--)
#define ll long long
int main(){
    faster();
    run(){
        string s;cin>>s;
        stack<int>st;
        for(int i=s.size()-1;i>=0;i--){
            if(isdigit(s[i])) st.push(s[i]-'0');
            else{
                int a=st.top();st.pop();
                int b=st.top();st.pop();
                if(s[i]=='+') st.push(a+b);
                else if(s[i]=='-') st.push(a-b);
                else if(s[i]=='*') st.push(a*b);
                else st.push(a/b);
            }
        }
        cout<<st.top()<<endl;
    }
}