#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t;cin>>t;while(t--)
#define ll long long
int main(){
    faster();
    run(){
        int s,t; cin>>s>>t;
        queue<pair<int,int>> q;// first: giá trị hiện tại của s, second: số bước;
        map<int,bool> check;
        q.push({s,0});
        while(q.front().first!=t){
            int x=q.front().first;
            int step=q.front().second;
            check[x]=1;
            q.pop();
            if(x<t && !check[x*2]){
                q.push({x*2,step+1});
            }
            if(!check[x-1]) q.push({x-1,step+1});
        }
        cout<<q.front().second<<endl;
    }
}