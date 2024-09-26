#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t; cin>>t; while(t--)
int n,m,check[501][501];
char A[501][501];
int dx[4]={-1,0,0,1};
int dy[4]={0,-1,1,0};
bool canmove(int i,int j){
    if(i<1 || i> n || j<1 || j>m) return false;
    if(A[i][j]=='*') return false;
    if(check[i][j]!=-1) return false;
    return true;
}
bool bfs(pair<int,int> p){
    queue<pair<int,int>>q;
    q.push(p);
    check[p.first][p.second]=0;
    while(!q.empty()){
        int i=q.front().first;
        int j=q.front().second;
        q.pop();
        if(check[i][j]>2) return false;
        for(int k=0;k<4;k++){
            int a=i+dx[k];
            int b=j+dy[k];
            while(canmove(a,b)){
                if(A[a][b]=='T') return true;
                q.push({a,b});
                check[a][b]=1+check[i][j];
                a+=dx[k];
                b+=dy[k];
            }
        }
    }
}
bool path(){
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(A[i][j]=='S'){
                return bfs({i,j});
            }
    return 0;
}
int main(){
    faster();
    run(){
        cin>>n>>m;
        memset(check,-1,sizeof(check));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>A[i][j];
            }
        }
        if(path()) cout<<"YES\n";
        else cout<<"NO\n";
    }
}