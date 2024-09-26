#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t;cin>>t;while(t--)
#define ll long long
ll so(string a){
    ll res=0;
    for(char c:a){
        res=res*10+c-'0';
    }
    return res;
}
int main(){
    faster();
    run(){
        int n;cin>>n;
        queue<string> q;
        q.push("1");
        while(1){
            string s=q.front();
            string a=s+"0";
            string b=s+"1";
            if(so(a)%n==0){
                cout<<a<<endl;
                break;
            }
            if(so(b)%n==0){
                cout<<b<<endl;
                break;
            }
            q.pop();
            q.push(a);q.push(b);
        }
    }
}