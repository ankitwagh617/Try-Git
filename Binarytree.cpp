#include <iostream>
using namespace std;

class Node
{
private:
    int data;
    Node *lchild;
    Node *rchild;
    public:
    Node(int x){
        data = x;
        Node*lchild = NULL;
        Node*rchild = NULL;
    }
    friend class Tree;
    friend class Queue;
};

class Queue
{
    int front;
    int rear;
    int size;
    Node **Q;

public:
    Queue()
    {
        front = rear = -1;
        size = 10;
        Q = new Node *[size];
    }
    Queue(int x)
    {
        front = rear = -1;
        this->size = size;
        Q = new Node *[this->size];
    }
    int isEmpty(){
        return front == rear;
    }
    void enqueue(Node *x)
    {
        
        if (rear == size - 1)
        {
            cout << "Queue full\n";
        }
        else
        {
            rear++;
            Q[rear] = x;
        }
        
    }
    Node*dequeue()
    {
        Node *x = NULL;
        if (front == rear)
        {
            cout << "Queue empty\n";
        }
        else
        {
            x = Q[front + 1];
            front++;
        }
        return x;
    }
    
};

class Tree{
    public:
    Node*root;
    Tree(){
        root = NULL;
    }
    void CreateTree(){
        Node*p,*t;
        int x;

        Queue q(100);
        cout<<"Enter the root value: ";
        cin>> x;
        root = new Node;
        root->data=x;
        root->lchild=NULL;
        root->rchild=NULL;
        q.enqueue(root);

        while(!q.isEmpty()){
            p = q.dequeue(); 
            cout<<"Enter the left child of"<<p->data<<": ";
            cin >> x;
            if(x!=-1){
                t = new Node;
                t->data=x;
                t->lchild = NULL;
                t->rchild=  NULL;
                p->lchild = t;
                q.enqueue(t);
            }
            cout<<"Enter the right child of"<<p->data<<": ";
            cin >> x;
            if(x!=-1){
                t = new Node;
                t->data=x;
                t->lchild = NULL;
                t->rchild=  NULL;
                p->rchild = t;
                q.enqueue(t);
            }

        }
    }
    void Preorder( Node*p){
        if(p){
            cout<<p->data;
            Preorder(p->lchild);
            Preorder(p->rchild);
        }
    }
    void Inorder( Node*p){
        if(p){
            Preorder(p->lchild);
            cout<<p->data;
            Preorder(p->rchild);
        }
    }
    void Postorder( Node*p){
        if(p){
            Preorder(p->lchild);
            Preorder(p->rchild);
            cout<<p->data;
        }
    }
};

int main(){
    Tree t;
    t.CreateTree();
    t.Preorder(t.root);
}