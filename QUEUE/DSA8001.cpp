#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t;cin>>t;while(t--)
#define ll long long
int main(){
    faster();
    run(){
        int n;cin>>n;
        queue<int> q;
        while(n--){
            int a;cin>>a;
            if(a==1) cout<<q.size()<<endl;
            if(a==2){
                if(q.empty()) cout<<"YES"<<endl;
                else cout<<"NO"<<endl;
            }
            if(a==3){
                int b;cin>>b;
                q.push(b);
            }
            if(a==4){
                if(q.size()) q.pop();
            }
            if(a==5){
                if(q.empty()) cout<<-1<<endl;
                else cout<<q.front()<<endl;
            }
            if(a==6){
                if(q.empty()) cout<<-1<<endl;
                else cout<<q.back()<<endl;
            }
        }
    }
}