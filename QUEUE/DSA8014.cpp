#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t;cin>>t;while(t--)
#define ll long long
int r,c,ans;
int dx[4]={-1,0,0,1};
int dy[4]={0,-1,1,0};
int a[505][505];
struct seed{
    int x,y,res;
};
int bfs(){
    seed u,v;
    queue<seed> q;
    u.res=0;
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            if(a[i][j]==2){
                u.x=i;
                u.y=j;
                q.push(u);
            }
        }
    }
    while(q.size()){
        seed f=q.front();q.pop();
        ans=max(ans,f.res);
        for(int i=0;i<4;i++){
            v.x=f.x+dx[i];
            v.y=f.y+dy[i];
            if(v.x>=1 && v.x<=r && v.y>=1 && v.y<=c && a[v.x][v.y]==1){
                a[v.x][v.y]=2;
                q.push({v.x,v.y,f.res+1});
            }
        }
    }
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            if(a[i][j]==1){
                ans=-1;
                break;
            }
        }
    }
    return ans;
}
int main(){
    faster();
    run(){
        cin>>r>>c;
        for(int i=1;i<=r;i++){
            for(int j=1;j<=c;j++){
                cin>>a[i][j];
            }
        }
        cout<<bfs()<<endl;
    }
}