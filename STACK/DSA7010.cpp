#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t;cin>>t;while(t--)
#define ll long long
int main(){
    faster();
    run(){
        string s;cin>>s;
        stack<string>st;
        for(int i=s.length()-1;i>=0;i--){
            if(isalpha(s[i])){
                st.push(string(1,s[i]));
            }
            else{
                string a=st.top();st.pop();
                string b=st.top();st.pop();
                string t=a+b+s[i];
                st.push(t);
            }
        }
        cout<<st.top()<<endl;
    }
}