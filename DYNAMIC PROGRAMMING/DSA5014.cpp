#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t; cin>>t; while(t--)
#define ll long long 
string dp[101];
string add(string a,string b){
    int n=max(a.size(),b.size());
    while(a.size()<n) a="0"+a;
    while(b.size()<n) b="0"+b;
    if(a<b) swap(a,b);
    string ans;
    int rem=0;
    for(int i=n-1;i>=0;i--){
        int tmp=(a[i]-'0') + (b[i]-'0') + rem;
        if(tmp>=10){
            tmp%=10;
            rem=1;
        }
        else rem=0;
        ans.push_back(tmp+'0');
    }
    if(rem>0) ans.push_back(rem+'0');
    reverse(ans.begin(),ans.end());
    return ans;
}
/*
    a*b
*/
string multiply(string a,string b){
    string res="0";
    int n=a.size();
    int m=b.size();
    int rem;
    for(int i=m-1;i>=0;i--){
        string tmp=string(m-i-1,'0');
        rem=0;
        for(int j=n-1;j>=0;j--){
            int d=(b[i]-'0')*(a[j]-'0')+rem;
            tmp=to_string(d%10) + tmp;
            rem=d/10;
        }
        if(rem>0) tmp=to_string(rem)+tmp;
        res=add(res,tmp);
    }   
    return res;
}
void era(){
    dp[0]=dp[1]="1";
    for(int n=2;n<=100;n++){
        for(int i=0;i<=n-1;i++){
            dp[n]=add(dp[n],multiply(dp[i],dp[n-i-1]));
        }
    }
}
int main(){
    faster();
    era();
    run(){
        int n;cin>>n;
        cout<<dp[n]<<endl;
    }
}