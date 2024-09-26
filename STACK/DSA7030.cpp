#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t;cin>>t;while(t--)
#define ll long long
int n,m,a[505][505];
int max_area(int x[]){
    stack<int> st;
    int res=0,i=0;
    while(i<=m){
        if(st.empty() || x[i]>=x[st.top()]){
            st.push(i);
            i++;
        }
        else{
            int idx=st.top();
            st.pop();
            if(st.empty()) res=max(res,i*x[idx]);
            else res = max(res,x[idx]*(i-st.top()-1));
        }
    }
    while(!st.empty()){
        int idx=st.top();
        st.pop();
        if(st.empty()) res=max(res,i*x[idx]);
        else res=max(res, x[idx]*(i-st.top()-1));
    }
    return res;
}
int main(){
    faster();
    run(){
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
            }
        }
        int b[505][505];
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(i==1) b[i][j]=a[i][j];
                else if(a[i][j]) b[i][j]=b[i-1][j]+1;
                else b[i][j]=0;
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            ans=max(ans,max_area(b[i]));
        }
        cout<<ans<<endl;
    }
}