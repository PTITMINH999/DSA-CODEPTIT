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

int size(node *head){
    int dem=0;
    while(head!=NULL){
        dem++;
        head = head->next;
    }
    return dem;
}

void popFront(node *&head){
    if(head==NULL) return;
    node *tmp=head;
    head=head->next;
    delete tmp;
}

void popBack(node *&head){
    if(head==NULL) return;
    node *tmp=head;
    if(tmp->next==NULL){
        head=NULL;
        delete tmp;
        return;
    }
    while(tmp->next->next != NULL){
        tmp=tmp->next;
    }
    node *last = tmp->next;
    tmp->next = NULL;
    delete last;
}

void erase(node *&head,int k){
    int n = size(head);
    if(k<1 || k>n) return;
    if(k==1) popFront(head);
    else{
        node *tmp=head;
        for(int i=1;i<=k-1;i++){
            tmp=tmp->next;
        }
        node *kth = tmp->next;
        tmp->next = kth->next;
        delete kth;
    }
}