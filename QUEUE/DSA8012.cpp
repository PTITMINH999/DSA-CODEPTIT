#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t;cin>>t;while(t--)
#define ll long long
bool check(string s){
    int m[10]={0};
    for(int i=0;i<s.size();i++){
        if(s[i]-'0' >5) return 0;
        m[s[i]-'0']++;
    }
    for(int i=0;i<10;i++){
        if(m[i]>1) return 0;
    }
    return 1;
}
int main(){
    faster();
    run(){
        int l,r;cin>>l>>r;
        int ans=0;
        for(int i=l;i<=r;i++){
            if(check(to_string(i))) ans++;
        }
        cout<<ans<<endl;
    }
}