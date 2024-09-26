#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t; cin >> t; while (t--)
#define ll long long
vector<int> a[200001];
ll value[200001];
int n;
int dfs(int u){
    value[u]=1;
    int size=0;// luu so con dinh u
    for(int v:a[u]){
        size+= dfs(v);
        value[u]+=value[v];
    }
    value[u]+=size;
    return size+1;
}
int main(){
    faster();
    cin>>n;
    for(int i=2;i<=n;i++){
        int x; cin>>x;
        a[x].push_back(i);
    }
    dfs(1);
    for(int i=1;i<=n;i++)
        cout<<value[i]<<" ";
}