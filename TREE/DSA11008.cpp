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
bool check;
int firstlv;
void traversal(bintree root,int level){
    if(root==NULL || !check) return;
    if(root->left==NULL && root->right==NULL){
        // nút lá đầu tiên 
        if(firstlv==-1) firstlv=level;
        // lá thứ 2,2,... khác lá thứ nhất 
        else if(firstlv != level){
            check=0;
            return;
        }
    }
    // duyệt đến khi gặp lá
    else{
        traversal(root->left,level+1);
        traversal(root->right,level+1);
    }
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
        --n;
        while(n--){
            cin>>par>>child>>c;
            buildTree(root,c,par,child);
        }
        check=1;
        firstlv=-1;
        traversal(root,0);
        cout<<check<<endl;
    }
}
