#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t; cin >> t; while (t--)
int n,m,k,M[1000];
bool check[1001];
vector<int> A[1001];
void dfs(int u){
    check[u]=true;
    for(int v:A[u]){
        if(!check[v]) dfs(v);
    }
}
int main(){
    cin>>k>>n>>m;
    for(int i=1;i<=k;i++) cin>>M[i];
    for(int i=1;i<=m;i++){
        int a,b; cin>>a>>b;
        A[a].push_back(b);
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        memset(check,false,sizeof(check));
        dfs(i);
        int x=0;
        // Với mỗi điểm đếm xem có bao nhiêu người duyệt qua nó
        for(int j=1;j<=k;j++) if(check[M[j]]) x++;
        // với mỗi điểm nếu =K lần duyệt thì đỉnh đó có gọp mặt đủ K người 
        if(x==k) ans++;
    }
    cout<<ans;
}