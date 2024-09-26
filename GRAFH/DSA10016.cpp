#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define p(d) pair<double,double>
 double kc[1000][1000];
double dis(p(d) a, p(d) b){
    return sqrt((a.first-b.first)*(a.first-b.first) + (a.second-b.second)*(a.second-b.second));
}
struct edge{
    int u,v;
    double w;
};
int n;
vector<edge> canh;
int parent[1001],sz[1001];
void make_set(){
    for(int i=1;i<=n;i++){
        parent[i]=i;
        sz[i]=1;
    }
}
int find(int v){
    if(v==parent[v]) return v;
    return parent[v]=find(parent[v]);
}
bool Union(int a,int b){
    a=find(a); b=find(b);
    if(a==b) return false;// không thể thêm ab vào cây khung
    if(sz[a]<sz[b]) swap(a,b);
    parent[b]=a;
    sz[a]+=sz[b];
    return true;
}
void nhap(){
    cin>>n;
    vector<p(d)> M(n);
    for(auto &x:M) cin>>x.first>>x.second;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            kc[i][j]=dis(M[i-1],M[j-1]);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
           canh.push_back({i,j,kc[i][j]});
        }
    }
}
bool cmp(edge a, edge b){
    return a.w<b.w;
}
void kruskal(){
    //Tao cay khung cuc tieu rong
    vector<edge> mst;
    double d=0;
    // Sort danh sách theo chiều dài tăng dần
    sort(canh.begin(),canh.end(),cmp);
    for(auto e:canh){
        if(mst.size()==n-1) break;
        if(Union(e.u,e.v)){
            mst.push_back(e);
            d+=e.w;
        }
    }
    cout<<setprecision(6)<<fixed<<d<<endl;
}
int main(){
    int t; cin>>t;
    while(t--){
        canh.clear();
        nhap();
        make_set();
        kruskal();
    }
}