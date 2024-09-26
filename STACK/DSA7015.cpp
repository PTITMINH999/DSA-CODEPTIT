#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t;cin>>t;while(t--)
#define ll long long
int pre(char c){
    if(c=='*'||c=='/') return 2;
    else if(c=='+'||c=='-') return 1;
    return 0;
}
ll tinh(ll a,ll b,char c){
    if(c=='+') return a+b;
    else if(c=='-') return a-b;
    else if(c=='*') return a*b;
    else return a/b;
}
void solve(string s){
    stack<char> st1;
    stack<ll> st2;
    for(int i=0;i<s.size();i++){
        if(s[i]=='(') st1.push(s[i]);
        else if(isdigit(s[i])){
            ll tmp=0;
            // push số có nhiều chữ số
            while(i<s.size() && isdigit(s[i])){
                tmp=tmp*10+s[i]-'0';i++;
            }
            --i;st2.push(tmp);
        }
        // Tính toán trong ngoặc trước
        else if(s[i]==')'){
            while(st1.size() && st1.top()!='('){
                ll a=st2.top();st2.pop();
                ll b=st2.top();st2.pop();
                st2.push(tinh(b,a,st1.top()));
                st1.pop();
            }
            if(!st1.empty()) st1.pop();// pop '('
        }
        // ưu tiên '*''/' trước '+''-' sau
        else{
            while(st1.size() && pre(s[i])<=pre(st1.top())){
                ll a=st2.top();st2.pop();
                ll b=st2.top();st2.pop();
                st2.push(tinh(b,a,st1.top()));
                st1.pop();
            }
            st1.push(s[i]);
        }
    }
    // Vx còn toán tử trong st1 thì tính toán nốt
    while(st1.size()){
        ll a=st2.top();st2.pop();
        ll b=st2.top();st2.pop();
        st2.push(tinh(b,a,st1.top()));
        st1.pop();
    }
    cout<<st2.top()<<endl;
}
int main(){
    faster();
    run(){
        string s;cin>>s;
        solve(s);
    }
}