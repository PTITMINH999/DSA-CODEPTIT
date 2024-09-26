#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t; cin>>t; while(t--)
#define ll long long
int main(){
    faster();
    run(){
        int n,x; cin>>n>>x;
        int a[n];
        for(int &i:a) cin>>i;
        int j=1;
        while(j<n &&a[j]>a[j-1]) j++;
        int *it=lower_bound(a,a+j,x);
        if(it==a+j || *it!=x){
            it=lower_bound(a+j,a+n,x);
        }
        cout<<it-a+1<<endl;
    }
}