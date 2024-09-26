#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t;cin>>t;while(t--)
#define ll long long
int n;
char A[100][100];
bool visited[100][100];
struct p{
    int a,b,res;// a,b lưu tọa độ, res lưu số bước 
};
int bfs(p s,p e){
    s.res=0;
    queue<p> q;
    q.push(s);
    while(!q.empty()){
        p f=q.front();
        q.pop();
        int x=f.a;
        int y=f.b;
        if(x==e.a && y==e.b) return f.res;
        // Di chuyển theo cột xuống dưới
        for(int i=x+1;i<n;i++){
            if(!visited[i][y] && A[i][y]!='X'){
                q.push({i,y,f.res+1});
                visited[i][y]=1;
            }
            else break;
        }
        // lên trên
        for(int i=x-1;i>=0;i--){
            if(!visited[i][y] && A[i][y]!='X'){
                q.push({i,y,f.res+1});
                visited[i][y]=1;
            }
            else break;
        }
        // di chuyển theo hàng sang phải
        for(int i=y+1;i<n;i++){
            if(!visited[x][i] && A[x][i]!='X'){
                q.push({x,i,f.res+1});
                visited[x][i]=1;
            }
            else break;
        }
        // sang trái
        for(int i=y-1;i>=0;i--){
            if(!visited[x][i] && A[x][i]!='X'){
                q.push({x,i,f.res+1});
                visited[x][i]=1;
            }
            else break;
        }
    }
    return -1;
}
int main(){
    faster();
    run(){
        memset(visited,false,sizeof(visited));
        cin>>n;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>A[i][j];
        p s,e;
        cin>>s.a>>s.b>>e.a>>e.b;
        cout<<bfs(s,e)<<endl;
    }
}