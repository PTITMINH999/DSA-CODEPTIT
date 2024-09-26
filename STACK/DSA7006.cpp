#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t;cin>>t;while(t--)
#define ll long long
set<string> x;
queue<string> q;
void xoadaungoac(string s){
    vector<pair<int,int>> v;// Lưu vị trí dấu ngoặc: first='('; second=')'
    stack<int>st;
    for(int i=0;i<s.length();i++){
        if(s[i]=='(') st.push(i);
        if(s[i]==')'){
            v.push_back({st.top(),i});
            st.pop();
        }
    }
    // Xóa các dấu ngoặc và lưu theo thứ tự từ điển
    for(auto it:v){
        string t=s;
        t.erase(it.first,1);
        t.erase(it.second-1,1);// do xóa một'(' nên phải lùi lại 1 vị trí để xóa')'
        if(x.find(t)==x.end()){
            q.push(t);
            x.insert(t);
        }
    }
}
int main(){
    faster();
    string a;cin>>a;
    q.push(a);
    while(!q.empty()){
        string b= q.front();
        q.pop();
        xoadaungoac(b);
    }
    for(auto i:x) cout<<i<<endl;
}