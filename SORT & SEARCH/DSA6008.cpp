#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t; cin>>t; while(t--)
#define ll long long
int d[5];
//x<y ---> x^y>y^x
// tìm vị trí xuất hiện đầu tiên của ptu > x nằm trong đoạn [l,r] của mảng y
int first_pos(int a[],int l,int r,int x){
    int res=-1;
    while(l<=r){
        int m=(l+r)/2;
        if(a[m]>x){
            res=m;
            r=m-1;
        }
        else l=m+1;
    }
    return res;
}
// Đếm xem số phần tử thuộc mảng y mà x^y>y^x
int cnt(int b[],int m,int x){
    if(x==0) return 0;
    if(x==1) return d[0];
    ll res=d[0]+d[1];
    int l=first_pos(b,0,m-1,x);
    if(l!=-1){
        res+=m-l;
    }
    if(x==2) res-=(d[3]+d[4]);
    if(x==3) res+=d[2];
    return res;
}
int main(){
    faster();
    run(){
        int n,m;
        cin>>n>>m;
        int a[n],b[m];
        for(int &x:a) cin>>x;
        for(int i=0;i<m;i++){
            cin>>b[i];
            if(b[i]<=4){
                d[b[i]]++;
            }
        }
        sort(b,b+m);
        ll ans=0;
        for(int x:a){
            ans+=cnt(b,m,x);
        }
        cout<<ans<<endl;
        memset(d,0,sizeof(d));
    }
}