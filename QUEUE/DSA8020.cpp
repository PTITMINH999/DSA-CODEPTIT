#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t;cin>>t;while(t--)
#define ll long long
bool check[10000];
void era(){
    for(int i=2;i<=100;i++){
        if(!check[i]){
            for(int j=i*i;j<=10000;j+=i){
                check[j]=1;
            }
        }
    }
}
int bfs(string s,string t){
    queue<pair<string,int>> q;
    q.push({s,0});
    set<string> st;
    st.insert(s);
    while(q.size()){
        auto x=q.front();q.pop();
        if(x.first==t) return x.second;
        string a=x.first;
        for(int i=0;i<4;i++){
            int c=(i==0)?1:0;
            for(int j=c;j<10;j++){
                a[i]=j+'0';
                if(st.count(a)==0 && !check[stoi(a)]){
                    st.insert(a);
                    q.push({a,x.second+1});
                }
            }
            a=x.first;
        }
    }
    return -1;
}
int main(){
    faster();
    run(){
        string s,t;cin>>s>>t;
        memset(check,false,sizeof(check));
        era();
        cout<<bfs(s,t)<<endl;
    }
}