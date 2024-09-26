#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t; cin>>t; while(t--)
#define ll long long
// F[i][j]: Xâu con bắt đầu từ chỉ số i và kết thúc ở chỉ số j
int main(){
    faster();
    run(){
        string s;cin>>s;
        int n=s.size();
        s="0"+s;
        bool F[n+1][n+1];
        memset(F,0,sizeof(F));
        for(int i=1;i<=n;i++) F[i][i]=1;// xâu con có độ dài bằng 1
        int ans=1;
        // Duyệt từ xâu con có độ dài =2
        for(int len=2;len<=n;len++){
            for(int i=1;i<=n-len+1;i++){
                int j=i+len-1;
                if(len==2 && s[i]==s[j]) F[i][j]=1;
                else{
                    F[i][j]= F[i+1][j-1] && (s[i]==s[j]);
                }
                if(F[i][j]) ans=max(ans,len);
            }
        }
        cout<<ans<<endl;
    }
}