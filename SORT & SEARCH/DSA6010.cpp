#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t; cin>>t; while(t--)
#define ll long long
int main(){
    faster();
    run(){
        int n; cin>>n;
        cin.ignore();
        string s; getline(cin,s);
        int a[10]={0};
        for(char x:s){
            if(isdigit(x)){
                a[x-'0']=1;
            }
        }
        for(int i=0;i<10;i++){
            if(a[i]) cout<<i<<" ";
        }
        cout<<endl;
    }

}