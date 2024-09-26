#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t; cin>>t; while(t--)
#define ll long long
int main(){
    faster();
    ll f[93];
    f[1]=f[2]=1;
    for(int i=3;i<=92;i++) f[i]=f[i-1]+f[i-2];
    run(){
        int n,k;
        cin>>n>>k;
        while(n>2){
            if(k > f[n-2]){
                k-=f[n-2];
                n--;
            }
            else n-=2;
        }
        string s[3];
        s[1]="0";
        s[2]="1";
        cout<<s[n][k-1]<<endl;
    }
}