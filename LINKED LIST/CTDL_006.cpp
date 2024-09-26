#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t; cin>>t; while(t--)
struct node{
    int data;
    struct node *next;
};
node *makeNode(int x){
    node *newNode=new node();
    newNode->data=x;
    newNode->next=NULL;
    return newNode;
}
bool Find(node *head,int x){
    if(head==NULL) return 1;
    while(head != NULL){
        if(head->data == x) 
            return 0;
        head=head->next;
    }
    return 1;
}
void pushback(node *&head,int x){
    node *tmp=head;
    node *newNode = makeNode(x);
    if(head == NULL){
        head=newNode;
        return;
    }
    while(tmp->next !=NULL){
        tmp = tmp->next;
    }
    tmp->next = newNode;
}
int main(){
    faster();
    int n,x;
    cin>>n;
    node *head=NULL;
    while(n--){
        cin>>x;
        if(Find(head,x)) pushback(head,x);
    }
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
    delete head;
}