#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t;cin>>t;cin.ignore();while(t--)
#define ll long long
int main(){
    string s;cin>>s;
    stack<char> x,y; // y:lưu kết quả
    for(int i=0;i<s.size();i++){
        if(s[i]=='<'){
            if(x.size()){
                y.push(x.top());
                x.pop();
            }
        }
        else if(s[i]=='>'){
            if(y.size()){
                x.push(y.top());
                y.pop();
            }
        }
        else if(s[i]=='-'){
            if(x.size()) x.pop();
        }
        else x.push(s[i]);
    }
    while(x.size()){
        y.push(x.top());x.pop();
    }
    while(y.size()){
        cout<<y.top();y.pop();
    }
}