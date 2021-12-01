#include<iostream>
#include<stdlib.h>
using namespace std;

class node{
    public:
    int data;
    node*next;
    node*prev;

    node(int val){
        data=val;
        node*next=NULL;
        node*prev=NULL;
    }
};

void insertAtHead(node* &head,int val){
    node* n=new node(val);

    n->next=head;
    if(head!=NULL){
        head->prev=n;
    }
    head=n;
}

void insertAtTail(node* &head,int val){
    node* n =new node(val);
    node* temp=head;

    if(head=NULL){
        insertAtHead(head,val);
        return;
    }

    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next = n;
    n->prev= temp;
}

void display(node*head){
    node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main(){
    node*head=NULL;
    insertAtHead(head,7);
    
    display(head);

}