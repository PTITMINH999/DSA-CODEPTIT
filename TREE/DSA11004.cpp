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
void levelOrder(bintree root){
    queue<bintree> q;
    q.push(root);
    while(q.size()){
        bintree f=q.front();
        q.pop();
        cout<<f->data<<' ';
        if(f->left!=NULL) q.push(f->left);
        if(f->right!=NULL) q.push(f->right);
    }
}
int main(){
    faster();
    run(){
        int n; cin>>n;
        bintree root=NULL;
        int u,v;
        char c;
        cin>>u>>v>>c;
        root = makenode(u);
        buildTree(root,c,u,v);
        n--;
        while(n--){
            cin>>u>>v>>c;
            buildTree(root,c,u,v);
        }
        levelOrder(root);
        cout<<endl;
    }
}