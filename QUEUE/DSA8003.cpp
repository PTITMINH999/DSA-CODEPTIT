#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t;cin>>t;while(t--)
#define ll long long
int main(){
    faster();
    int n;cin>>n;
    deque<int> q;
    while(n--){
        string s;cin>>s;
        if(s=="PUSHFRONT"){
            int a;cin>>a;
            q.push_front(a);
        }
        if(s=="PRINTFRONT"){
            if(q.empty()) cout<<"NONE\n";
            else cout<<q.front()<<endl;
        }
        if(s=="POPFRONT" && q.size()){
            q.pop_front();
        }
        if(s=="PUSHBACK"){
            int b;cin>>b;
            q.push_back(b);
        }
        if(s=="PRINTBACK"){
            if(q.empty()) cout<<"NONE\n";
            else cout<<q.back()<<endl;
        }
        if(s=="POPBACK" && q.size()){
            q.pop_back();
        }
    }
}