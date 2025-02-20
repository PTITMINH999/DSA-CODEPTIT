#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t; cin>>t; while(t--)
#define ll long long
int res = 1;
vector<map<int,int>> dp;
bool check(int len,int x,int y){
    auto it = dp[len].lower_bound(x);
    if(it==dp[len].begin()){
        return false;
    }
    it--;
    return it->second < y;
}
void add(int len,int x,int y){
    auto it = dp[len].lower_bound(x);
    auto tmp = it;
    while(it!=dp[len].end() && it->second >= y){
        it++;
    }
    dp[len].erase(tmp,it);
    dp[len].insert({x,y});
}
int main(){
    faster();
    int n;
    cin>>n;
    dp.resize(n+1);
    add(0,INT_MIN,INT_MIN);
    while(n--){
        int x,y; cin>>x>>y;
        int l = 0,r = res;
        while(l<=r){
            int mid =(l+r)/2;
            if(check(mid,x,y)){
                l=mid+1;
            }
            else r=mid-1;
        }
        if(res==l-1) res++;
        add(l,x,y);
    }
    cout<<res<<endl;
    // for(int i=1;i<=res;i++){
    //     for(auto v:dp[i]){
    //         cout<<v.first<<' '<<v.second<<endl;
    //     }
    // }
}