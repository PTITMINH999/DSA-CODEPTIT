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
int level[1005];
int a[35];
void traversal(bintree root,int lv){
    if(root==NULL) return;
    level[lv]++;
    //depth=max(depth,lv);
    traversal(root->left,lv+1);
    traversal(root->right,lv+1);
}
string solve(){
    for(int i=0;i<=30;i++){
        if(level[i]==0) return "Yes";
        if(level[i] != a[i]){
            return "No";
        }
    }
    return "Yes";
}
int main(){
    faster();
    for(int i=0;i<=30;i++){
        a[i]=pow(2,i);
    }
    run(){
        int n; cin>>n;
        memset(level,0,sizeof(level));
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
        traversal(root,0);
        cout<<solve()<<endl;
    }
}