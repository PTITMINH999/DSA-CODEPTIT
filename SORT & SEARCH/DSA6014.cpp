#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t; cin>>t; while(t--)
#define ll long long
vector<int> prime(1000005,1);
void sieve(){
    prime[0]=prime[1]=0;
    for(int i=2;i<=1000;i++){
        if(prime[i]){
            for(int j=i*i;j<=1000000;j+=i){
                prime[j]=0;
            }
        }
    }
}
int main(){
    faster();
    run(){
        sieve();
        int n;cin>>n;
        int ok=0;
        for(int i=2;i<n;i++){
            if(prime[i]&&prime[n-i]){
                ok=1;
                cout<<i<<" "<<n-i<<endl;
                break;
            }
        }
        if(!ok) cout<<-1<<endl;
    }
}