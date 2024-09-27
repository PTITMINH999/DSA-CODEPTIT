#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t;cin>>t;while(t--)
#define ll long long
int main(){
    faster();
    run(){
        int n,par,child;
        char c;
        cin>>n;
        set<int> st;
        while(n--){
            cin>>par>>child>>c;
            if(st.size()==0)
                st.insert(par);
            st.insert(child);
        }
        for(int x:st) cout<<x<<' ';
        cout<<endl;
    }
}