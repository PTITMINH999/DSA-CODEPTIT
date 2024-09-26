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
        st.push(-1);
        int res=-1;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(') st.push(i);
            else{
                st.pop();
                if(st.empty()) st.push(i);
                else res=max(res,i-st.top());
            }
        }
        cout<<res<<endl;
    }
}