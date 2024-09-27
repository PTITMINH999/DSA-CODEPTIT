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
    if(root!=NULL){
        if(root->data == u){
            if(c=='L') root->left=makenode(v);
            else root->right=makenode(v);
        }
        buildTree(root->left,c,u,v);
        buildTree(root->right,c,u,v);
    }
}
bool check;
void order(bintree root){
    if(!check) return;
    if(root){
        if((root->left==NULL && root->right) || (root->left && root->right==NULL)){
            check=0;
            return;
        }
        if(root->left) order(root->left);
        if(root->right) order(root->right);
    }
}
int main(){
    faster();
    run(){
        int n; cin>>n;
        int par,child;
        char c;
        cin>>par>>child>>c;
        bintree root=NULL;
        root=makenode(par);
        buildTree(root,c,par,child);
        n--;
        while(n--){
            cin>>par>>child>>c;
            buildTree(root,c,par,child);
        }
        check=1;
        order(root);
        cout<<check<<endl;
    }
}
