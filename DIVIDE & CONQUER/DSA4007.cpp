#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t; cin>>t; while(t--)
#define ll long long
int heso10(int x,int k){
    int sum=0;
    string s=to_string(x);
    for(int i=0;i<s.length();i++){
        sum=sum*k+s[i]-'0';
    }
    return sum;
}
int main(){
    faster();
    run(){
        int k,a,b;
        cin>>k>>a>>b;
        int sum=heso10(a,k)+heso10(b,k);
        string ans="";
        while(sum){
            ans=to_string(sum%k) +ans;
            sum/=k;
        }
        cout<<ans<<endl;
    }
}