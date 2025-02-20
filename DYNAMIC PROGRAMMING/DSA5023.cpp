#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t; cin>>t; while(t--)
#define ll long long
/*
1 = 1
12 +2= 1*10 + 2*2
123+23+3 = 14*10 + 3*3 
*/
int main(){
    faster();
    run(){
        string s;cin>>s;
        int n=s.size();
        s=" "+s;
        ll dp[n+1]={};
        ll sum=0;
        for(int i=1;i<=n;i++){
            dp[i]=dp[i-1]*10 + (s[i]-'0')*i;
            sum+=dp[i];
        }
        cout<<sum<<endl;
    }
}