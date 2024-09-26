#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t;cin>>t;while(t--)
#define ll long long
int main(){
    faster();
    run(){
        int n;cin>>n;
        int a[n];
        for(int &x:a) cin>>x;
        int m[10]={0};
        int sum=0;
        for(int i=0;i<n;i++){
            m[a[i]]++;
            sum+=a[i];
        }
        bool check=0;
        if(sum%3==1){
            if(m[1]>0) m[1]--,check=1;
            else if(m[4]>0) m[4]--,check=1;
            else if(m[7]>0) m[7]--,check=1;
        }
        else if(sum%3==2){
            if(m[5]>0) m[5]--,check=1;
            else if(m[8]>0) m[8]--,check=1;
            else if(m[2]>0) m[2]--,check=1;
        }
        else check=1;
        if(!check){
            cout<<-1<<endl;
            continue;
        }
        int k=10,ok=1;
        while(k--){
            while(m[k]--){
                cout<<k;
                ok=0;
            }
        }
        if(ok) cout<<-1;
        cout<<endl;
    }
}