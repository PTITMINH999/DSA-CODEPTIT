#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t;cin>>t;while(t--)
#define ll long long
int dx[8]={2,2,1,1,-1,-1,-2,-2};
int dy[8]={-1,1,-2,2,-2,2,-1,1};
bool check[10][10];
struct banco{
    int x,y,cnt;
};
int bfs(banco a,banco b){
    queue<banco> q;
    //a.cnt=0;
    q.push(a);
    check[a.x][a.y]=1;
    while(q.size()){
        banco f=q.front();q.pop();
        if(f.x==b.x && f.y==b.y) return f.cnt;
        for(int i=0;i<8;i++){
            int u=f.x+dx[i];
            int v=f.y+dy[i];
            if(u>=1 && u<=8 && v>=1 && v<=8 && !check[u][v]){
                check[u][v]=1;
                q.push({u,v,f.cnt+1});
            }
        }
    }
    return -1;
}
int main(){
    faster();
    run(){
        memset(check,false,sizeof(check));
        string s,t; cin>>s>>t;
        banco a={s[0]-'a'+1,s[1]-'0',0};
        banco b={t[0]-'a'+1,t[1]-'0',0};
        cout<<bfs(a,b)<<endl;
    }
}