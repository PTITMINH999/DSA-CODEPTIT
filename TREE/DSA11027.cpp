#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t;cin>>t;while(t--)
#define ll long long
struct node{
    int val;
    node *left,*right;
};
typedef node* bintree;
bintree makenode(int x){
    bintree res= new node;
    res->val=x;
    res->left = res->right = NULL;
    return res;
}
bintree buildTree(int a[],int l,int r){
    if(l>r) return NULL;
    int mid=(l+r)/2;
    bintree root=makenode(a[mid]);
    root->left= buildTree(a,l,mid-1);
    root->right=buildTree(a,mid+1,r);
    return root;
}
int ans;
void order(bintree A){
    if(A){
        if(A->left==NULL && A->right==NULL)
            ++ans;
        else{
            if(A->left) order(A->left);
            if(A->right) order(A->right);
        }
    }
}
int main(){
    faster();
    run(){
        int n; cin>>n;
        int a[n];
        for(int &x:a) cin>>x;
        sort(a,a+n);
        bintree A = buildTree(a,0,n-1);
        ans=0;
        order(A);
        cout<<ans<<endl;    
    }
}
