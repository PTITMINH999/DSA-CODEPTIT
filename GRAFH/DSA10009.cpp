#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
int n,m;
int mat[101][101];
void nhap(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j) mat[i][j]=0;
            else mat[i][j]=1e9;
        }
    }
    while(m--){
        int u,v,w; cin>>u>>v>>w;
        mat[u][v]=w;
        mat[v][u]=w;
    }
}
void Floyd(){
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(mat[i][j]>mat[i][k]+mat[k][j])
                    mat[i][j]=mat[i][k]+mat[k][j];
            }
        }
    }
}
int main(){
    faster();
    nhap();
    Floyd();
    int q; cin>>q;
    while(q--){
        int a,b; cin>>a>>b;
        cout<<mat[a][b]<<endl;
    }
}