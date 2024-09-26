#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t;cin>>t;while(t--)
#define ll long long
int pos=0;// vị trí hiện tại trong preorder
void print(int inorder[],int preorder[], int l,int r, unordered_map<int,int> &m){
    if(l<=r){
        int idx=m[preorder[pos++]];
        print(inorder,preorder,l,idx-1,m);
        print(inorder,preorder,idx+1,r,m);
        cout<<inorder[idx]<<" ";
    }
}
int main(){
    faster();
    run(){
        int n; cin>>n;
        int inorder[n], preorder[n];
        for(int &x:inorder) cin>>x;
        for(int &x:preorder) cin>>x;
        unordered_map<int,int> m;
        for(int i=0;i<n;i++){
            m[inorder[i]]=i;
        }
        pos=0;
        print(inorder,preorder,0,n-1,m);
        cout<<endl;
    }
}