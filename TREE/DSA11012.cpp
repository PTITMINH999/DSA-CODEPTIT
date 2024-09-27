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
bool check(bintree root1, bintree root2){
    if(root1==NULL && root2==NULL)
        return 1;
    if(root1!=NULL && root2!=NULL){
        return root1->data==root2->data
        && check(root1->left,root2->left) && check(root1->right,root2->right);
    }
    return 0;
}
int main(){
    faster();
    run(){
        int n; cin>>n;
        int par,child;
        char c;
        cin>>par>>child>>c;
        bintree root1=NULL;
        root1=makenode(par);
        buildTree(root1,c,par,child);
        n--;
        while(n--){
            cin>>par>>child>>c;
            buildTree(root1,c,par,child);
        }
        int m; cin>>m;
        cin>>par>>child>>c;
        bintree root2=NULL;
        root2=makenode(par);
        buildTree(root2,c,par,child);
        m--;
        while(m--){
            cin>>par>>child>>c;
            buildTree(root2,c,par,child);
        }
        cout<<check(root1,root2)<<endl;
    }
}