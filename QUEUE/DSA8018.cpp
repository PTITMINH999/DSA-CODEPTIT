#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t;cin>>t;while(t--)
#define ll long long
vector<string> res;
int main(){
    faster();
    run(){
        res.clear();
        int n;cin>>n;
        queue<string> q;
        q.push("6");
        q.push("8");
        int l=0;
        while(l<=n){
            string s=q.front();
            q.pop();
            res.push_back(s);
            q.push(s+"6");
            q.push(s+"8");
            l=q.front().length();
        }
        cout<<res.size()<<endl;
        for(string x:res) cout<<x<<" ";
        cout<<endl;
    }
}