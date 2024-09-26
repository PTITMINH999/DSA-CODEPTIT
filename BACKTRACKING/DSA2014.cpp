#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t; cin>>t; while(t--)
int m,n,k,ok;
string a[5][5];
bool check[5][5];
int dx[8]={-1,-1,-1,0,0,1,1,1};
int dy[8]={-1,0,1,-1,1,-1,0,1};
set<string> se,s1;
void Try(int i,int j,string s){
    if(se.find(s)!=se.end()){
        ok=1;
        s1.insert(s);
    }
    for(int k=0;k<8;k++){
        int u=i+dx[k];
        int v=j+dy[k];
        if(u>=0 && u<m && v>=0 && v<n && !check[u][v]){
            check[u][v]=1;
            Try(u,v,s+a[u][v]);
            check[u][v]=0;
        }
    }
}
int main(){
    faster();
    run(){
        cin>>k>>m>>n;
        string s="";
        ok=0;
        memset(check,false,sizeof(check));
        se.clear();s1.clear();
        while(k--){
            string c;cin>>c;
            se.insert(c);
        }
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                cin>>a[i][j];

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                check[i][j]=1;
                Try(i,j,s+a[i][j]);
                check[i][j]=0;
            }
        }
        if(!ok) cout<<-1;
        for(string it:s1) cout<<it<<" ";
        cout<<endl;
    }
}