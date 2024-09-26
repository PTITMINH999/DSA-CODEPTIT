#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t;cin>>t;while(t--)
#define ll long long
int n;
string a[150];
struct node{
    string s;
    node *left,*right;
};
typedef node* bintree;
bintree makenode(string s){
    bintree newNode= new node;
    newNode->s=s;
    newNode->left=newNode->right=NULL;
    return newNode;
}
bintree buildTree(bintree root,int i){
    if(i<n){
        root=makenode(a[i]);
        root->left=buildTree(root->left,2*i+1);
        root->right=buildTree(root->right,2*i+2);
    }
    return root;
}
ll calc(bintree root){
    if(root->s =="+") return calc(root->left)+calc(root->right);
    else if(root->s =="-") return calc(root->left)-calc(root->right);
    else if(root->s =="*") return calc(root->left)*calc(root->right);
    else if(root->s =="/") return calc(root->left)/calc(root->right);
    else return stoll(root->s);
}
int main(){
    faster();
    run(){
        cin>>n;
        int i=0;
        for(int i=0;i<n;i++) cin>>a[i];
        bintree root=NULL;
        root = buildTree(root,0);
        cout<<calc(root)<<endl;
        delete root;
    }
}