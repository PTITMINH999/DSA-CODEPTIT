#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t;cin>>t;while(t--)
#define ll long long
struct node{
    int data;
    node *left,*right;
};
typedef node* bintree;
bintree makenode(int x){
    bintree newNode = new node;
    newNode->data=x;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}
void buildTree(bintree &root,char c,int u,int v){
    if(root==NULL) return;
    if(root->data == u){
        if(c=='L') root->left=makenode(v);
        else root->right=makenode(v);
    }
    buildTree(root->left,c,u,v);
    buildTree(root->right,c,u,v);
}
int res;
int findMax(bintree A){
    if(A==NULL) return 0;
    int L=findMax(A->left) , R=findMax(A->right);
    if(A->left==NULL && A->right==NULL)
        return A->data;
    if(A->left==NULL)
        return R+A->data;
    if(A->right==NULL)
        return L+A->data;
    res=max(res,L+R+A->data);
    return max(L,R) + A->data;
}
int main(){
    faster();
    run(){
        int n; cin>>n;
        bintree root=NULL;
        int par,child;
        char c;
        cin>>par>>child>>c;
        root=makenode(par);
        buildTree(root,c,par,child);
        n--;
        while(n--){
            cin>>par>>child>>c;
            buildTree(root,c,par,child);
        }
        res=-1e9;
        findMax(root);
        cout<<res<<endl;
    }
}