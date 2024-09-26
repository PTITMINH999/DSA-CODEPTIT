#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t;cin>>t;while(t--)
#define ll long long
int main(){
    faster();
    run(){
        int n;cin>>n;
        int a[n];
        for(int &x:a) cin>>x;
        stack<int>st;
        int mini[n];// mảng lưu phần tử nhỏ hơn tiếp theo
        for(int i=n-1;i>=0;i--){
            while(st.size() && st.top()>=a[i]){
                st.pop();
            }
            if(st.empty()) mini[i]=-1;
            else mini[i]=st.top();
            st.push(a[i]);
        }
        stack<pair<int,int>> st2;//lưu a[i] và phần tử nhỏ hơn tiếp theo 
        int res[n];
        for(int i=n-1;i>=0;i--){
            // tìm phần tử lớn hơn đầu tiên 
            while(st2.size() && st2.top().first<=a[i]){
                st2.pop();
            }
            if(st2.empty()) res[i]=-1;
            else res[i]=st2.top().second;
            st2.push({a[i],mini[i]});
        }   
        for(int i=0;i<n;i++) cout<<res[i]<<" ";
        cout<<endl;
    }
}