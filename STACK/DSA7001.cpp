#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t;cin>>t;while(t--)
#define ll long long
int main(){
    faster();
    stack<int> st;
    int n;
    string s;
    while(cin>>s){
        if(s=="push"){
            cin>>n;
            st.push(n);
        }
        if(s=="pop" &&st.size()){
            st.pop();
        }
        if(s=="show"){
            vector<int>v;
            if(st.empty()) cout<<"empty"<<endl;
            while(!st.empty()){
                v.push_back(st.top());
                st.pop();
            }
            reverse(v.begin(),v.end());
            for(int i=0;i<v.size();i++){
                cout<<v[i]<<" ";
                st.push(v[i]);
            }
            cout<<endl;
        }
    }
}