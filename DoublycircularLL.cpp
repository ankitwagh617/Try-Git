#include <bits/stdc++.h>
using namespace std;

class node
{
    int data;
    node *next;
    node *prev;

public:
    friend class List;
    node()
    {
        data = 0;
        node *next = NULL;
        node *prev = NULL;
    }
    node(int d)
    {
        data = d;
        node *next = NULL;
        node *prev = NULL;
    }
};
class List
{
    node *start;

public:
    List()
    {
        start = NULL;
    }
    void insert_start(int x)
    {
        node *p;
        p = new node(x);
        if (start == NULL)
        {
            start = p;
            p->next = start;
            p->prev = start;
        }
        else
        {
            p->next = start;
            p->prev = start->prev;
            start->prev->next = p;
            start->prev = p;
            start = p;
        }
    }

    void insert_end(int x)
    {
        node *p, *temp;
        p = new node(x);
        if (start == NULL)
        {
            start = p;
            p->next = start;
            p->prev = start;
        }
        else
        {
            p->next = start;
            p->prev = start->prev;
            start->prev->next = p;
            start->prev = p;
        }
    }
    void display(){
        node*temp = start;
        cout<<"START"<<"->";
        cout<<temp ->data<<"->";
        temp = temp->next;
        while(temp!= start){
            cout<<temp->data<<"->";
            temp = temp->next;
        }
        cout<<"START"<<endl;
    }
};
int main(){
    List l;
    l.insert_start(2);
    l.insert_start(1);
    l.display();
    l.insert_end(3);
    l.insert_end(4);
    l.insert_end(5);
    l.insert_start(10);
    l.display();
}