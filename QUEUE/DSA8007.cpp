#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t;cin>>t;while(t--)
#define ll long long
int ans=0;
void check(string n){
    queue<string> q;
    q.push("1");
    while(q.size()){
        string s=q.front();
        q.pop();
        if(s.size()<n.size() || s.size()==n.size() && s<=n) ans++;
        else return;
        q.push(s+"0");
        q.push(s+"1");
    }
}
int main(){
    faster();
    run(){
        string n;cin>>n;
        ans=0;
        check(n);
        cout<<ans<<endl;
    }
}