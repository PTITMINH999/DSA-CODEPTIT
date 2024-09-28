#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t;cin>>t;while(t--)
#define ll long long
int n,par[1001];
void path(int e){
    stack<int> st;
    while(e!=1){
        st.push(e);
        e=par[e];
    }
    st.push(1);
    while(st.size()){
        cout<<st.top()<<' ';
        st.pop();
    }
}   
int main(){
    faster();
    run(){
        int n; cin>>n;
        // kiểm tra xem có phải node trung gian ko
        bool check[n+1]={};
        for(int i=2;i<=n;i++){
            int x,y; cin>>x>>y;
            par[y]=x;
            check[x]=1;
        }
        for(int i=2;i<=n;i++){
            if(!check[i]){
                path(i);
                cout<<endl;
            }
        }
    }
}