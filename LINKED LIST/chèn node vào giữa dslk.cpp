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

void duyet(node *head){
    while(head != NULL){
        cout<<head->data<<' ';
        head = head->next;
    }
}

void pushFront(node *&head,int x){
    node *newNode = makeNode(x);
    newNode->next = head;
    head=newNode;
}

void pushBack(node *&head,int x){
    node *tmp=head;
    node *newNode = makeNode(x);
    if(head==NULL){
        head=newNode;
        return;
    }
    while(tmp->next !=NULL){
        tmp=tmp->next;
    }
    tmp->next = newNode;
}

void insert(node *&head,int k,int x){
    int n=size(head);
    if(k<1 || k>n+1) return;
    if(k==1){
        pushFront(head,x);
        return;
    }
    node *tmp=head;
    for(int i=1;i<=k-2;i++){
        tmp=tmp->next;
    }
    node *newNode = makeNode(x);
    newNode->next= tmp->next;
    tmp->next=newNode;
}

int main(){
	node *head = NULL;
	while(1){
		cout << "------------------------------------\n";
		cout << "1. Them vao dau\n";
		cout << "2. Them vao cuoi\n";
		cout << "3. Them vao giua\n";
		cout << "4. Duyet\n";
		cout << "0. Thoat !\n";
		cout << "------------------------------------\n";
		cout << "Nhap lua chon :";
		int lc; cin >> lc;
		if(lc == 1){
			int x; cout << "Nhap x :"; cin >> x;
			pushFront(head, x);
		}
		else if(lc == 2){
			int x; cout << "Nhap x :"; cin >> x;
			pushBack(head, x);
		}
		else if(lc == 3){
			int x; cout << "Nhap x :"; cin >> x;
			int k; cout << "Nhap k :"; cin >> k;
			insert(head, k, x);
		}
		else if(lc == 4){
			duyet(head);
			cout << endl;
		}
		else{
			break;
		}
	}
	return 0;
}