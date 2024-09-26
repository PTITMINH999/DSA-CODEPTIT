#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
int n,m;
int a[505][505];
bool visited[505][505];
int dx[8]={-1,-1,-1,0,0,1,1,1};
int dy[8]={-1,0,1,-1,1,-1,0,1};
void dfs(int i,int j){
    visited[i][j]=true;
    for(int k=0;k<8;k++){
        int i1=i+dx[k];
        int j1=j+dy[k];
        if(i1>=1 && i1<=n && j1>=1 && j1<=m && !visited[i1][j1] && a[i1][j1]==1){
            dfs(i1,j1);
        }
    }
}
int main(){
    faster();
    int t; cin>>t;
    while(t--){
        memset(visited,false,sizeof(visited));
        cin>>n>>m;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                cin>>a[i][j];
        int cnt=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(a[i][j]==1 && !visited[i][j]){
                    cnt++;
                    dfs(i,j);
                }
            }
        }
        cout<<cnt<<endl;
    }
}
