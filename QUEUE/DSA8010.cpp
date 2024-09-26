#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t;cin>>t;while(t--)
#define ll long long
int main(){
    faster();
    run(){
        int n;cin>>n;
        queue<int> q;
        q.push(n);
        unordered_map<int,int> step;// lưu số bước 
        step[n]=0;
        while(q.front()!=1){
            int x=q.front(); q.pop();
            int sqr=sqrt(x);
            // Tìm ước của x
            for(int i=2;i<=sqr;i++){
                if(x%i) continue;// Nếu ko chia hết thì bỏ qua
                int umax=x/i;
                if(step[umax]) continue;
                q.push(umax);
                step[umax]=step[x]+1;
            }
            if(!step[x-1]){
                q.push(x-1);
                step[x-1]=step[x]+1;
            }
        }
        cout<<step[q.front()]<<endl;
    }
}