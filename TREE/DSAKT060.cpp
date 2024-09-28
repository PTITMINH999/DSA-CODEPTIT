#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t;cin>>t;while(t--)
#define ll long long
int main(){
    faster();
    string s; cin>>s;
    int q; cin>>q;
    while(q--){
        char c; cin>>c;
        if(c=='q'){
            int l,r; cin>>l>>r;
            string tmp=s;
            reverse(tmp.begin()+l-1,tmp.begin()+r);
            if(tmp==s) cout<<"YES\n";
            else cout<<"NO\n";
        }
        else{
            int u; cin>>u;
            char x; cin>>x;
            s[u-1]=x;
        }
    }
}