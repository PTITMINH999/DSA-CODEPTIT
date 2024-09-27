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
void buildTree(bintree &A,int val){
    if(A==NULL) A=makenode(val);
    else{
        if(A->val < val) buildTree(A->right,val);
        else buildTree(A->left,val);
    }
}
void preorder(bintree A){
    if(A!=NULL){
        cout<<A->val<<' ';
        preorder(A->left);
        preorder(A->right);
    }
}
int main(){
    faster();
    run(){
        int n,val; cin>>n;
        bintree A=NULL;
        while(n--){
            cin>>val;
            buildTree(A,val);
        }
        preorder(A);
        cout<<"\n";
    }
}