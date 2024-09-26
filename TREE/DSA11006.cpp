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
    if(root!=NULL){
        if(root->data == u){
            if(c=='L') root->left=makenode(v);
            else root->right=makenode(v);
        }
        buildTree(root->left,c,u,v);
        buildTree(root->right,c,u,v);
    }
}
void spiral(bintree root){
    stack<bintree> s1,s2;
    s1.push(root);
    while(s1.size() || s2.size()){
        while(s1.size()){
            bintree top=s1.top(); s1.pop();
            cout<<top->data<<' ';
            if(top->right!=NULL) s2.push(top->right);
            if(top->left!=NULL) s2.push(top->left);
        }
        while(s2.size()){
            bintree top=s2.top(); s2.pop();
            cout<<top->data<<' ';
            if(top->left!=NULL) s1.push(top->left);
            if(top->right!=NULL) s1.push(top->right);
        }
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
        --n;
        while(n--){
            cin>>par>>child>>c;
            buildTree(root,c,par,child);
        }
        spiral(root);
        cout<<endl;
    }
}