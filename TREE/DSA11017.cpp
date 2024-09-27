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
void buildTree(bintree &root,int val){
    if(root==NULL){
        root=makenode(val);
        return;
    }
    if(root->data > val)
        buildTree(root->left,val);
    else 
        buildTree(root->right,val);
}
void postorder(bintree A){
    if(A!=NULL){
        postorder(A->left);
        postorder(A->right);
        cout<<A->data<<' ';
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
        postorder(A);
        cout<<endl;
    }
}