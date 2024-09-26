#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t; cin>>t; while(t--)
int main(){
    faster();
    int n; cin>>n;
    int a[n];
    for(int &x:a) cin>>x;
    for(int i=0;i<n-1;i++){
        int min=i;
        for(int j=i+1;j<n;j++){
            if(a[j]<a[min]) min=j;
        }
        swap(a[i],a[min]);
        cout<<"Buoc "<<i+1<<": ";
        for(int x:a) cout<<x<<" ";
        cout<<endl;
    }
}