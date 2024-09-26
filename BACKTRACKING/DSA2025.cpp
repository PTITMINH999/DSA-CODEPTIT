#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t; cin>>t; while(t--)
#define ll long long
int n,res=1e9;
int a[50],b[50],dup[50][50]={};
vector<string> v(20);
int count(string x,string y){
    int i=0,j=0,cnt=0;
    while(i<x.size() && j<y.size()){
        if(x[i]==y[j]){
            cnt++;i++;j++;
        }
        else if(x[i]<y[j]){
            i++;
        }
        else j++;
    }
    return cnt;
}
void update(){
    int cnt=0;
    for(int i=1;i<=n;i++) cnt+=dup[a[i-1]][a[i]];
    res=min(res,cnt);
}
void Try(int i){
    for(int j=1;j<=n;j++){
        if(b[j]==0){
            a[i]=j;
            b[j]=1;
            if(i==n) update();
            else Try(i+1);
            b[j]=0;
        }
    }
}
int main(){
    faster();
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>v[i];
        b[i]=0;
    }
    // dup[i][j]: số kí tự lặp của 2 xâu v[i],v[j].
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dup[i][j]=dup[j][i]=count(v[i],v[j]);
        }
    }
    Try(1);
    cout<<res;
}   