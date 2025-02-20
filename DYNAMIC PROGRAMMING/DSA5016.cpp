#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t; cin>>t; while(t--)
#define ll long long
vector<ll> a; 
// void era(){
//     priority_queue<ll,vector<ll>,greater<ll>> pq;
//     unordered_map<ll,bool> mp;
//     pq.push(1);
//     mp[1]=1;
//     while(pq.size()<10000){
//         ll x=pq.top();pq.pop();
//         a.push_back(x);
//         if(!mp[x*2]){
//             pq.push(x*2);
//             mp[x*2]=1;
//         }
//         if(!mp[x*3]){
//             pq.push(x*3);
//             mp[x*3]=1;
//         }
//         if(!mp[x*5]){
//             pq.push(x*5);
//             mp[x*5]=1;
//         }
//     }
//     for(auto it:mp){
//         if(it.second==1) a.push_back(it.first);
//     }
// }
int uglyNumber(int n)
    {   
       vector<int> dp(n);
       dp[0]=1;
       int p1=0,p2=0,p3=0;
       for(int i=1;i<n;i++){
            int two = dp[p1] * 2;
            int three = dp[p2] * 3;
            int five = dp[p3] * 5;
            dp[i] = min(two,min(three, five));
            if (dp[i] == two) p1++;
            if (dp[i] == three) p2++;
            if (dp[i] == five) p3++;
       }
       return dp[n-1];
    }
int main(){
    faster();
    //era();
    run(){
        ll n;cin>>n;
        cout<<uglyNumber(n)<<endl;
    }
}