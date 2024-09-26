#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t;cin>>t;while(t--)
#define ll long long
char A[31][31][31];
bool check[31][31][31];
int a,b,c;
int dx[6]={1,-1,0,0,0,0};
int dy[6]={0,0,1,-1,0,0};
int dz[6]={0,0,0,0,1,-1};
struct hhcn{
    int x,y,z;
};
bool solve(int m,int n,int p){
    if(m>=1&&m<=a && n>=1&&n<=b && p>=1&&p<=c && A[m][n][p]!='#' && !check[m][n][p]) return 1;
    return 0;
}
int bfs(hhcn s,hhcn e){
    queue<pair<hhcn,int>> q;
    q.push({s,0});
    check[s.x][s.y][s.z]=1;
    while(q.size()){
        auto f=q.front();
        q.pop();
        if(f.first.x==e.x && f.first.y==e.y &&f.first.z==e.z) return f.second;
        for(int i=0;i<6;i++){
            int m=f.first.x+dx[i];
            int n=f.first.y+dy[i];
            int p=f.first.z+dz[i];
            if(solve(m,n,p)){
                q.push({{m,n,p},f.second+1});
                check[m][n][p]=1;
            }
        }
    }
    return -1;
}
int main(){
    faster();
    run(){
        memset(check,false,sizeof(check));
        cin>>a>>b>>c;
        hhcn s,e;
        for(int i=1;i<=a;i++){
            for(int j=1;j<=b;j++){
                for(int k=1;k<=c;k++){
                    cin>>A[i][j][k];
                    if(A[i][j][k]=='S') s={i,j,k};
                    if(A[i][j][k]=='E') e={i,j,k};
                }
            }
        }
        cout<<bfs(s,e)<<endl;
    }
}