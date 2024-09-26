#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
struct edge{
    int u,v;
    int w;
};
int n,m;
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
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y,w; cin>>x>>y>>w;
        edge e{x,y,w};
        canh.push_back(e);
    }
}
bool cmp(edge a, edge b){
    return a.w<b.w;
}
void kruskal(){
    //Tao cay khung cuc tieu rong
    vector<edge> mst;
    int d=0;
    // Sort danh sách theo chiều dài tăng dần
    sort(canh.begin(),canh.end(),cmp);
    for(int i=0;i<m;i++){
        if(mst.size()==n-1) break;
        edge e = canh[i];// chọn canh e là cạnh nhỏ nhất
        if(Union(e.u,e.v)){
            mst.push_back(e);
            d+=e.w;
        }
    }
    cout<<d<<endl;
}
int main(){
    faster();
    int t; cin>>t;
    while(t--){
        canh.clear();
        nhap();
        make_set();
        kruskal();
    }
}