#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t;cin>>t;while(t--)
#define ll long long
vector<int> quay1(vector<int> a){
    int tmp=a[0];
    a[0]=a[3];
    a[3]=a[4];
    a[4]=a[1];
    a[1]=tmp;
    return a;
}
vector<int> quay2(vector<int> a){
    int tmp=a[1];
    a[1]=a[4];
    a[4]=a[5];
    a[5]=a[2];
    a[2]=tmp;
    return a;
}
bool check(vector<int> a,vector<int> b){
    for(int i=0;i<6;i++) if(a[i]!=b[i]) return 0;
    return 1;
}
int main(){
    faster();
    run(){
        vector<int> a(6),b(6);
        queue<pair<vector<int>,int>> q;
        set<vector<int>> s;
        for(int i=0;i<6;i++) cin>>a[i];
        for(int i=0;i<6;i++) cin>>b[i];
        q.push({a,0});
        while(q.size()){
            vector<int> x=q.front().first;
            int res=q.front().second;
            q.pop();
            if(check(x,b)){
                cout<<res<<endl;
                break;
            }
            vector<int> y=x;
            vector<int> c=quay1(x),d=quay2(y);
            if(s.count(c)==0){
                s.insert(c);
                q.push({c,res+1});
            }
            if(s.count(d)==0){
                s.insert(d);
                q.push({d,res+1});
            }
        }
    }
}