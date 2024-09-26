#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
int a[1001][1001];
int main(){
    faster();
    int n; cin>>n;
    cin.ignore();
    memset(a,0,sizeof(a));
    for(int i=1;i<=n;i++){
        string s,num;
        getline(cin,s);
        stringstream ss(s);
        while(ss >> num){
            a[i][stoi(num)]=1;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<a[i][j]<<' ';
        }
        cout<<endl;
    }
}