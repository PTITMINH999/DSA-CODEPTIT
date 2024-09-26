#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t;cin>>t;while(t--)
#define ll long long
int main(){
    faster();
    run(){
        string s;cin>>s;
        stack<char> st;
        int ans=0;
        for(char c:s){
            if(c=='(') st.push(c);
            else{
                if(st.empty()){
                    ans++;
                    st.push('(');
                }
                else st.pop();
            }
        }
        cout<<ans+st.size()/2<<endl;
    }
}