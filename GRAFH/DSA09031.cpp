#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t; cin >> t; while (t--)
int n,m,k;
// vector<int> A[1001];
bool check[1001][1001];
int dx[4]={-1,0,0,1};
int dy[4]={0,-1,1,0};
set<pair<pair<int,int>,pair<int,int>>>s;
vector<pair<int,int>> v;
void dfs(pair<int,int> u){
    check[u.first][u.second] = true;
    for(int k=0;k<4;k++){
        int x=u.first+ dx[k];
        int y=u.second+ dy[k];
        if(x>=1 && x<=n && y>=1 && y<=n && !check[x][y] && s.find({u,{x,y}})==s.end()){
            dfs({x,y});
        }
    }
}
int main(){
    faster();
    cin>>n>>k>>m;
    for(int i=0;i<m;i++){
        int a,b,c,d; cin>>a>>b>>c>>d;
        s.insert({ {a,b},{c,d} });
		s.insert({ {c,d},{a,b} });
    }
    for(int i=0;i<k;i++){
        int x,y; cin>>x>>y;
        v.push_back({x,y});
    }
    int cnt=0;
    for(auto c:v){
        memset(check,false,sizeof(check));
        dfs(c);
        for(auto t:v){
            if(!check[t.first][t.second]) cnt++;
        }
    }
    cout<<cnt/2;
}
