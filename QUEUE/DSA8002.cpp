#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t;cin>>t;while(t--)
#define ll long long
int main(){
    faster();
    int n;cin>>n;
    queue<int> q;
    while(n--){
        string s;cin>>s;
        if(s=="PUSH"){
            int a;cin>>a;
            q.push(a);
        }
        if(s=="POP" && q.size()) q.pop();
        if(s=="PRINTFRONT"){
            if(q.empty()) cout<<"NONE\n";
            else cout<<q.front()<<endl;
        }
    }
}