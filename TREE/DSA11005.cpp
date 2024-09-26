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
bintree createNode(int x)
{
    bintree res = new node;
    res -> val = x;
    res -> left = res -> right = NULL;
    return res;
}
int level[1001], n;
unordered_map<int,int> indexOf;
bintree buildTree(int i,int l,int r){
    if(i>=n || l>r) return NULL;
    bintree root = createNode(level[i]);
    int m=indexOf[level[i]];
    root->left =buildTree(2*i+1,l,m-1);
    root->right=buildTree(2*i+2,m+1,r);
    return root;
}
void postorder(bintree root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        cout<<root->val<<" ";
    }
}
int main(){
    faster();
    run(){
        cin>>n;
        int inorder[n],e;
        for(int i=0;i<n;i++){
            cin>>e;
            indexOf[e]=i;
        }
        for(int i=0;i<n;i++){
            cin>>level[i];
        }
        bintree root=buildTree(0,0,n-1);
        postorder(root);
        cout<<endl;
        indexOf.clear();
    }
}