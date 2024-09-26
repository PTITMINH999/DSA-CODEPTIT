#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t;cin>>t;while(t--)
#define ll long long
string check(int n){
    queue<string> q;
    q.push("9");
    while(q.size()){
        string s=q.front();
        q.pop();
        if(stoll(s)%n==0) return s;
        q.push(s+"0");
        q.push(s+"9");
    }
}
int main(){
    faster();
    run(){
        int n;cin>>n;
        cout<<check(n)<<endl;
    }
}