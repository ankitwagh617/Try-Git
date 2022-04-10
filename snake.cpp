#include <iostream>
using namespace std;

class Node
{
    int data;
    Node *next;
    Node *prev;

public:
    friend class List;
    Node()
    {
        data = 0;
        Node *next = NULL;
        Node *prev = NULL;
    }
    Node(int d)
    {
        data = d;
        Node *next = NULL;
        Node *prev = NULL;
    }
};
class List
{
    Node *head;

public:
    List()
    {
        head = NULL;
    }
    void insertAtStart(int x)
    {
        Node *n = new Node(x);
        n->next = head;
        if (head == NULL)
        {
            head = n;
        }
        else
        {
            head->prev = n;
            head = n;
        }
    }
    void insertAtEnd(int x)
    {
        Node *n = new Node(x);
        if (head == NULL)
        {
            n->next = head;
            head = n;
        }
        else
        {
            Node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = n;
            n->prev = temp;
        }
    }

    void display(){
        Node*temp = head;
        while(temp!=NULL){
            cout<<temp->data<<"->";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }
};

int main(){
    List l;
    l.insertAtEnd(1);
    l.insertAtStart(2);
    l.display();
    l.insertAtEnd(3);
    l.insertAtStart(4);
    l.display();
}