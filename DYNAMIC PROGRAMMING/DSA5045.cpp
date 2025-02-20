#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t; cin>>t; while(t--)
#define ll long long
struct Item{
    int value,weight;
};
bool cmp(Item a,Item b){
    double r1=((double)a.value/(double)a.weight);
    double r2=((double)b.value/(double)b.weight);
    return r1>r2;
}
int main(){
    faster();
    run(){
        int n,w;
        cin>>n>>w;
        Item a[n];
        for(int i=0;i<n;i++){
            cin>>a[i].value>>a[i].weight;
        }
        sort(a,a+n,cmp);
        double ans = 0;
        for(int i=0;i<n;i++){
            if(w-a[i].weight >=0 ){
                ans+=a[i].value;
                w-=a[i].weight;
                if(w==0) break;
            }
            else{
                ans+=(a[i].value/(double)a[i].weight)*(double)w;
                break;
            }
        }
        cout<<fixed<<setprecision(2)<<ans<<endl;
    }
}