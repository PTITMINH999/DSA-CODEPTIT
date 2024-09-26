#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t;cin>>t;cin.ignore();while(t--)
#define ll long long
int main(){
    faster();
    run(){
        int n;cin>>n;
        int a[n];
        for(int &i:a) cin>>i;
        stack<int>st;
        vector<int>v;
        for(int i=0;i<n;i++){
            while(st.size() && a[i]>=a[st.top()]){
                st.pop();
            }
            if(st.empty()) v.push_back(i+1);
            else v.push_back(i-st.top());
            st.push(i);
        }
        for(int x:v) cout<<x<<" ";
        cout<<endl;
    }
}