#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
int m[1001][1001];
vector<int> a[1001];
int main(){
    faster();
    int n; cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>m[i][j];
            if(m[i][j]) a[i].push_back(j);
        }
    }
    for(int i=1;i<=n;i++){
        for(int x:a[i]) cout<<x<<" ";
        cout<<endl;
    }
}