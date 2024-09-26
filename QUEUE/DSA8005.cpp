#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t;cin>>t;while(t--)
#define ll long long
vector<string> res;
void init(){
    queue<string> q;
    q.push("1");
    res.push_back("1");
    while(res.size()<10000){
        string s=q.front();
        q.pop();
        res.push_back(s+"0");
        res.push_back(s+"1");
        q.push(s+"0");
        q.push(s+"1");
    }
}
int main(){
    faster();
    init();
    run(){
        int n;cin>>n;
        for(int i=0;i<n;i++){
            cout<<res[i]<<" ";
        }
        cout<<endl;
    }
}