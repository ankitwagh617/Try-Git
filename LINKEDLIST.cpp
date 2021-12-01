#include<iostream>
#include<stdlib.h>
using namespace std;
class Node
{
    public:
    int data;
    Node* next;
};
void display(Node*n){
    while(n!=NULL){
        cout<<n->data<<" ";
        n=n->next;
    }
}
int main(){
    Node*first = NULL;
    Node*second = NULL;
    Node*third = NULL;
    int A[4] = {100,200,300,400};

    first = new Node();
    second = new Node();
    third = new Node();

    first->data = A[3];
    first->next = second;

    second->data = A[2];
    second->next = third;

    third->data = A[1];
    third->next = NULL;

    

    

    display(first);
}