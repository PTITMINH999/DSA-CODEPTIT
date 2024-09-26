#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
int parent[1001];
int Size[1001];
int n;
void make_set(){
    for(int i=1;i<=n;i++){
        parent[i]=i;
        Size[i]=1;
    }
}
// Tìm gốc
int find(int v){
    if(v==parent[v]){
        return v;
    }
    return parent[v]=find(parent[v]);
}
// Hợp 2 tập hợp
void Union(int a,int b){
    a=find(a);
    b=find(b);
    if(a!=b){
        if(Size[a]<Size[b]) swap(a,b);
        parent[b]=a;
        Size[a]+=Size[b];
    }
}
