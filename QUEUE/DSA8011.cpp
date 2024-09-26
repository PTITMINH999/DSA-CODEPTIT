#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t;cin>>t;while(t--)
#define ll long long
set<string> st;
int bfs(string a,string b){
    if(a==b || st.find(b)==st.end()) return 0;
    int len=a.size();
    queue<pair<string,int>> q;// Lưu xâu hiện tại và đường đi ngắn nhất
    q.push({a,1});
    while(q.size()){
        string s=q.front().first;
        int res=q.front().second;
        if(s==b) return res;
        q.pop();
        for(int i=0;i<len;i++){
            char c=s[i];
            // Duyệt trâu để tìm từ khác 1 ký tự
            for(int j='A';j<='Z';j++){
                s[i]=j;
                if(s==b) return res+1;
                if(st.find(s)!=st.end()){
                    st.erase(s);
                    q.push({s,res+1});
                }
            }
            s[i]=c;// Thay đổi 1 chữ cái để thành từ hiện tại
        }
    }
}
int main(){
    faster();
    run(){
        st.clear();
        int n;
        string s,t;
        cin>>n>>s>>t;
        while(n--){
            string a;cin>>a;
            st.insert(a);
        }
        cout<<bfs(s,t)<<endl;
    }
}