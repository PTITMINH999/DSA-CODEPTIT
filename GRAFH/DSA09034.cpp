#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t; cin >> t; while (t--)
int n,m;
int dx[8]={-1,-1,-1,0,0,1,1,1};
int dy[8]={-1,0,1,-1,1,-1,0,1};
bool check[101][101];
char A[101][101];
void dfs(int x,int y){
    check[x][y]=true;
    for(int k=0;k<8;k++){
        int a=x+dx[k];
        int b=y+dy[k];
        if(a>=1 && a<=n && b>=1 && b<=m && !check[a][b] && A[a][b]=='W'){
            dfs(a,b);
        }
    }
}
int main(){
    cin>>n>>m;
    //memset(check,false,sizeof(check));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>A[i][j];
            check[i][j]=false;
        }
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(!check[i][j] && A[i][j]=='W'){
                cnt++;
                dfs(i,j);
            }
        }
    }
    cout<<cnt;
}