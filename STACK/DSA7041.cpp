#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t;cin>>t;cin.ignore();while(t--)
#define ll long long
int main(){
    faster();
    run(){
        string s;cin>>s;
        int cnt=0;
        while(true){
            int pos=s.find("()");
            if(pos==-1) break;
            else{
                cnt+=2;
                s.erase(pos,2);
            }
        }
        cout<<cnt<<endl;
    }
}