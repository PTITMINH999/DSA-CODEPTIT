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

void duyet(node *head){
    while(head != NULL){
        cout<<head->data<<' ';
        head = head->next;
    }
}

void pushback(node *&head,int x){
    node *tmp=head;
    node *newNode = makeNode(x);
    if(head==NULL){
        head=newNode;
        return;
    }
    while(tmp->next !=NULL){
        tmp=tmp->next;
    }
    // cho phan next cua node tmp -> newnode
    tmp->next = newNode;
}
int main(){
    faster();
    node *head= NULL;
    for(int i=1;i<=10;i++){
        pushback(head,i);
    }
    duyet(head);
}