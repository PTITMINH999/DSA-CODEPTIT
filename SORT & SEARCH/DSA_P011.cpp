#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t; cin>>t; while(t--)
char a[100][100];
int n,m;
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
void dfs(int i,int j){
    a[i][j]='.';
    for(int k=0;k<4;k++){
        int x = i+dx[k];
        int y = j+dy[k];
        if(x>=0 && x<n && y>=0 && y<m && a[x][y]=='#'){
            dfs(x,y);
        }
    }
}
int main(){
    faster();
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    int cnt = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]=='#'){
                cnt++;
                dfs(i,j);
            }
        }
    }
    cout<<cnt;
}