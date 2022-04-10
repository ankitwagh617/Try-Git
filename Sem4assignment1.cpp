#include <iostream>
using namespace std;

class Node
{
private:
    int data;
    Node *left;
    Node *right;

public:
    friend class Tree;
    friend class Queue;
    friend class Stack;
    Node()
    {
        data = 0;
        Node *left = NULL;
        Node *right = NULL;
    }
    Node(int x)
    {
        data = x;
        Node *left = NULL;
        Node *right = NULL;
    }
};

class stack{
    int top;
    int size;
    Node **S;
    public:
    stack(){
        top = -1;
        size = 10;
        S = new Node*[size];
    }
    stack(int size){
        top =-1;
        this->size = size;
        S = new Node*[this->size];
    }
    int isEmpty(){
        return top = -1;
    }
    int isFull(){
        return  top = size -1;
    }
    void push(Node* x){
        if(top == size -1){
            cout<<"Stack is Full\n";
        }
        else{
            top++;
            S[top] = x;
        }
    }
    Node*pop(){
        Node *x=NULL;
        if(top == -1){
           cout<<"Stack is empty\n"; 
        }
        else{
            
            x = S[top];
            top--;
        }
        return x;
    }
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
    Queue(int size)
    {
        front = rear = -1;
        this->size = size;
        Q = new Node *[this->size];
    }
    int isEmpty()
    {
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
    Node *dequeue()
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

class Tree
{
public:
    Node *root;
    Tree()
    {
        root = NULL;
    }
    // recursive methods-
    void createtree();
    void preorder(Node *p);
    void postorder(Node *p);
    void inorder(Node *p);
    //Non-recursive methods-
    void Ipreorder(Node*p);
};

void Tree::createtree()
{
    Node *p, *t;
    int x;
    Queue q(100);

    cout << "Enter root value :";
    cin >> x;
    root = new Node;
    root->data = x;
    root->left = NULL;
    root->right = NULL;

    q.enqueue(root);

    while (!q.isEmpty())
    {
        p = q.dequeue();
        cout << "Enter left child of " << p->data << " -->> ";
        cin >> x;
        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->left = t->right = NULL;
            p->left = t;
            q.enqueue(t);
        }
        cout << "Enter right child of " << p->data << " -->> ";
        cin >> x;
        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->left = t->right = NULL;
            p->right = t;
            q.enqueue(t);
        }
    }
}

void Tree::preorder(Node *p)
{
    if (p)
    {
        cout << p->data << " ";
        preorder(p->left);
        preorder(p->right);
    }
}

void Tree ::inorder(Node *p)
{
    if (p)
    {
        inorder(p->left);
        cout << p->data << " ";
        inorder(p->right);
    }
}

void Tree ::postorder(Node *p)
{
    if (p)
    {
        postorder(p->left);
        postorder(p->right);
        cout << p->data << " ";
    }
}
void Tree::Ipreorder(Node*p)
{
    stack stk(100);
    
    while ( !stk.isEmpty())
    {
        if (p)
        {
            cout << p->data << " ";
            stk.push(p);
            p = p->left;
        }
        else
        {
            p = stk.pop();
            p = p->right;
        }
    }
}

int main()
{
    Tree t;
    t.createtree();
    t.Ipreorder(t.root);

    // int choice;
    // int var = 1, ans;

    // while (var == 1)
    // {
    //     cout << "MENU\n";
    //     cout << "------------------------------------\n";
    //     cout << "Enter the following choice:\n";
    //     cout << "1)Preorder Traversing.\n";
    //     cout << "2)Inorder Traversing.\n";
    //     cout << "3)Postorder Traversing.\n";
    //     cin >> choice;
    //     if (choice == 1)
    //     {
    //         cout << endl;
    //         cout << "Preorder is:-->>";
    //         t.preorder(t.root);
    //     }
    //     else if (choice == 2)
    //     {
    //         cout << endl;
    //         cout << "Inorder is:-->>";
    //         t.inorder(t.root);
    //     }
    //     else if (choice == 3)
    //     {
    //         cout << endl;
    //         cout << "Postorder is: -->>";
    //         t.postorder(t.root);
    //     }
    //     else
    //     {
    //         cout << "Enter valid input\n";
    //     }
    //     cout << "\nDo you want to continue:(1/0)";
    //     cin >> ans;
    //     if (ans != 1)
    //     {
    //         break;
    //     }
    // }
}
