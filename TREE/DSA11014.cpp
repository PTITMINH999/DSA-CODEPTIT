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
ll sum;
bool isLeaf(bintree root){
    return root -> left == root -> right && root -> left == NULL;
}
void solve(bintree root){
    if(root==NULL) return;
    if(root->right!=NULL && isLeaf(root->right))
        sum+=root->right->data;
    if(root->right!=NULL && !isLeaf(root->right))
        solve(root->right);
    if(root->left!=NULL && !isLeaf(root->left))
        solve(root->left);
}
int main(){
    faster();
    run(){
        int n; cin>>n;
        bintree root=NULL;
        unordered_map<int,bintree> m;
        int par,child;
        char c;
        cin>>par>>child>>c;
        root=makenode(par);
        if(c == 'L')
        {
            root -> left = makenode(child);
            m[child] = root -> left;
        }
        else
        {
            root -> right = makenode(child);
            m[child] = root -> right;
        }
        m[par] = root;
        --n;
        while(n--){
            cin>>par>>child>>c;
            if(c == 'L')
            {
                root -> left = makenode(child);
                m[child] = m[par]->left;
            }
            else
            {
                root -> right = makenode(child);
                m[child] = m[par] -> right;
            }
        }
        sum=0;
        solve(root);
        cout<<sum<<endl;
    }
}

