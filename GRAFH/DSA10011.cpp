#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define pii pair<int,pair<int,int>>
int dx[4]={-1,0,0,1};
int dy[4]={0,-1,1,0};
int n,m,A[501][501],c[501][501];
void dijkstra(){
    c[1][1]=A[1][1];
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({c[1][1],{1,1}});
    while(pq.size()){
        pii t=pq.top(); pq.pop();
        int i=t.second.first;
        int j=t.second.second;
        for(int k=0;k<4;k++){
            int i0=i+dx[k];
            int j0=j+dy[k];
            if(i0<1 || i0>n || j0<1 || j0>m) continue;
            if(c[i0][j0] > c[i][j]+A[i0][j0]){
                c[i0][j0]= c[i][j]+A[i0][j0];
                pq.push({c[i0][j0],{i0,j0}});
            }
        }
    }

}
int main(){
    int t; cin>>t;
    while(t--){
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>A[i][j];
                c[i][j]=1e9;
            }
        }
        dijkstra();
        cout<<c[n][m]<<endl;
    }
}
