#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t;cin>>t;while(t--)
#define ll long long
//DDIDDIID
int main(){
    faster();
    run(){
        string s;cin>>s;
        stack<string> st;
        int cnt=2;
        st.push("1");
        for(char c:s){
            if(c=='I') st.push(to_string(cnt));
            else{
                string t=st.top();st.pop();
                t=to_string(cnt)+t;
                st.push(t);
            }
            cnt++;
        }
        string ans="";
        while(st.size()){
            ans=st.top()+ans;
            st.pop();
        }
        cout<<ans<<endl;
    }   
}