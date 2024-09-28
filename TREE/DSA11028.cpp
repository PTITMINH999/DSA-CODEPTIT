#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t;cin>>t;while(t--)
#define ll long long
int f[100005]={},res;
bool visited[100005];
int bfs(vector<int> a[]){
    queue<int> q;
    int top;
    q.push(1);
    visited[1]=1;
    while(!q.empty()){
        top=q.front();q.pop();
        for(int v:a[top]){
            if(!visited[v]){
                f[v] = f[top]+1;
                res=max(res,f[v]);
                q.push(v);
                visited[v]=1;
            }
        }
    }
    return res;
}
int main(){
    faster();
    run(){
        int n; cin>>n;
        n--;
        vector<int> a[n+5];
        for(int i=0;i<=100005;i++){
            f[i]=0;
            visited[i]=0;
        }
        res=-1;
        while(n--){
            int x,y;
            cin>>x>>y;
            a[x].push_back(y);
        }
        cout<<bfs(a)<<endl;
    }
}