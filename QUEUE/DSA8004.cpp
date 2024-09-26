#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t;cin>>t;while(t--)
#define ll long long
int main(){
    faster();
    run(){
        int n;cin>>n;
        string s;cin>>s;
        priority_queue<int> pq;
        int a[30]={};
        for(char c:s) a[c-'A']++;
        for(int i=0;i<26;i++){
            if(a[i]) pq.push(a[i]);
        }
        while(n--){
            int x=pq.top();
            pq.pop();
            x--;
            pq.push(x);
        }
        ll ans=0;
        while(!pq.empty()){
            ans+=1ll *pq.top()*pq.top();
            pq.pop();
        }
        cout<<ans<<endl;
    }
}