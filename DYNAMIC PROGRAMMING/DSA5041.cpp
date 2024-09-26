#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t; cin>>t; while(t--)
#define ll long long
int main(){
    faster();
    run(){
        string s;cin>>s;
        int n=s.size();
        int f[n+1][n+1];// độ dài dãy con từ i-->j
        memset(f,0,sizeof(f));
        for(int i=0;i<n;i++) f[i][i]=1;// xâu con có độ dài bằng 1
        for(int len=2;len<=n;len++){
            for(int i=0;i<=n-len;i++){
                if(s[i]==s[i+len-1]){
                    f[i][i+len-1]=f[i+1][i+len-2]+2;
                }
                else f[i][i+len-1]=max(f[i+1][i+len-1],f[i][i+len-2]);
            }
        }
        cout<<n-f[0][n-1]<<endl;
    }
}