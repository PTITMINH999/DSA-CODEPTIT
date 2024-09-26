#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t;cin>>t;while(t--)
#define ll long long
struct node{
    char c;
    node *left;
    node *right;
};
typedef node* bintree;
bintree makenode(char c){
    bintree newNode= new node;
    newNode->c = c;
    newNode->left = NULL;
    newNode->right=NULL;
    return newNode;
}
void inorder(bintree a){
    if(a!=NULL){
        inorder(a->left);
        cout<< a->c;
        inorder(a->right);
    }
}
int main(){
    faster();
    run(){
        string s; cin>>s;
        stack<bintree> st;
        for(char &i:s){
            if(isalpha(i)) st.push(makenode(i));
            else{
                bintree tmp= makenode(i);
                tmp->right=st.top();
                st.pop();
                tmp->left=st.top();
                st.pop();
                st.push(tmp);
            }
        }
        inorder(st.top());
        cout<<endl;
    }
}