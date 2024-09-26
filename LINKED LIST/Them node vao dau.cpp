#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t; cin>>t; while(t--)
struct node{
    int data;
    struct node *next;
};
node *makeNode(int x){
    node *newNode = new node();
    newNode ->data = x;
    newNode ->next =NULL;
    return newNode;
}

void duyet(node *head){
    while(head != NULL){
        cout<<head->data<<' ';
        head = head->next;
    }
}

int count(node *head){
    int dem=0;
    while(head!=NULL){
        dem++;
        head = head->next;
    }
    return dem;
}

void pushFront(node **head, int x){
    node *newNode=makeNode(x);
    //Buoc1: phan next cua newNode=>head
    newNode->next = *head;// *head=> dia chi cua node head trong dslk
    // Buoc2: Cap nhat node head => newNode
    *head=newNode;
}
void pushFront2(node *&head,int x){
    node *newNode = makeNode(x);
    newNode->next = head;
    head=newNode;
}
int main(){
    node *head=NULL;
    for(int i=1;i<=5;i++){
        pushFront(&head,i);
    }
     for(int i=10;i<=20;i++){
        pushFront2(head,i);
    }
    duyet(head);
    cout<<count(head);
}