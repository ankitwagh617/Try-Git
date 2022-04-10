#include <iostream>
using namespace std;
class node
{
public:
    node *left;
    int data;
    node *right;
};

class stack
{
    int size;
    int top;
    node **S;

public:
    void stackcreate(int size);
    void push(node *x);
    node *pop();
    int isemptystack();
    int isfullstack();
};

void stack ::stackcreate(int size)
{
    this->size = size;
    this->top = -1;
    this->S = new node *[size];
}

void stack ::push(node *x)
{
    if (this->top == this->size - 1)
    {
        cout << "Stack overflow" << endl;
    }
    else
    {
        this->top++;
        this->S[this->top] = x;
    }
}
node *stack ::pop()
{
    node *x = NULL;
    if (this->top == -1)
    {
        cout << "Stack Underflow" << endl;
    }
    else
    {
        x = this->S[this->top--];
    }
    return x;
}

int stack ::isemptystack()
{
    if (this->top == -1)
    {
        return 1;
    }
    return 0;
}

int stack ::isfullstack()
{
    return top == size - 1;
}

class queue
{
private:
    int front;
    int rear;
    int size;
    node **Q;

public:
    queue()
    {
        front = rear = -1;
        size = 10;
        Q = new node *[size];
    }
    queue(int size)
    {
        front = rear = -1;
        this->size = size;
        Q = new node *[this->size];
    }
    void enqueue(node *x);
    node *dequeue();
    int isempty()
    {
        return front == rear;
    }
    // int dequeue();
    void display();
};

void queue ::enqueue(node *x)
{
    if (rear == size - 1)
    {
        cout << "Queue Full" << endl;
    }
    else
    {
        rear++;
        Q[rear] = x;
    }
}

node *queue::dequeue()
{
    node *x = NULL;
    if (front == rear)
    {
        cout << "Queue is  empty" << endl;
    }
    else
    {
        x = Q[front + 1];
        front++;
    }
    return x;
}

void queue::display()
{
    for (int i = front + 1; i < rear; i++)
    {
        cout << Q[i];
    }
}

class tree
{
public:
    node *root;
    tree()
    {
        root = NULL;
    }
    void createtree();

    // recursive methods of traversals
    void preorder(node *p);
    void postorder(node *p);
    void inorder(node *p);
    void levelorder(node *p);
    int height(node *root);

    // iterative methods of traversal
    void Ipreorder(node *p);
    void Ipostorder(node *p);
    void Iinorder(node *p);

    int count(node *p);
};

void tree::createtree()
{
    node *p, *t;
    int x;
    queue q(100);

    cout << "Enter root value ";
    cin >> x;
    root = new node;
    root->data = x;
    root->left = root->right = NULL;

    q.enqueue(root);

    while (!q.isempty())
    {
        p = q.dequeue();
        cout << "Enter left child of " << p->data << " -->>";
        cin >> x;
        if (x != -1)
        {
            t = new node;
            t->data = x;
            t->left = t->right = NULL;
            p->left = t;
            q.enqueue(t);
        }
        cout << "Enter right child of " << p->data << " -->>";
        cin >> x;
        if (x != -1)
        {
            t = new node;
            t->data = x;
            t->left = t->right = NULL;
            p->right = t;
            q.enqueue(t);
        }
    }
}

void tree::preorder(node *p)
{
    if (p)
    {
        cout << p->data;
        preorder(p->left);
        preorder(p->right);
    }
}

void tree ::inorder(node *p)
{
    if (p)
    {
        inorder(p->left);
        cout << p->data;
        inorder(p->right);
    }
}

void tree ::postorder(node *p)
{
    postorder(p->left);
    postorder(p->right);
    cout << p->data;
}

int tree ::height(node *p)
{
    int x = 0, y = 0;
    if (root = 0)
    {
        return 0;
    }
    x = height(root->left);
    y = height(root->right);

    if (x > y)
    {
        return x + 1;
    }
    else
    {
        return y + 1;
    }
}
void tree ::levelorder(node *p)
{
    queue q(100);
    cout << root->data;
    q.enqueue(root);

    while (!q.isempty())
    {
        root = q.dequeue();
        if (root->left)
        {
            cout << root->left->data;
            q.enqueue(root->left);
        }
        if (root->right)
        {
            cout << root->right->data;
            q.enqueue(root->right);
        }
    }
}

void tree ::Ipreorder(node *p)
{
    stack stk;
    stk.stackcreate(100);
    while (p or !stk.isemptystack())
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

void tree ::Iinorder(node *p)
{
    stack stk;
    stk.stackcreate(100);
    while (p or !stk.isemptystack())
    {
        if (p)
        {
            stk.push(p);
            p = p->left;
        }
        else
        {
            p = stk.pop();
            cout << p->data << " ";
            p = p->right;
        }
    }
}

// int  tree :: count(node *p)
// {
//     if (p)
//     {
//         return count(p->left) + count(p->right)+1;
//     }
    
// }

// void tree :: Ipostorder(node *p)
// {
//     stack stk;
//     stk.stackcreate(100);
//     while (p or !stk.isemptystack())
//     { 
//         stk.push(p);
//         p = p->right;
//         p = p->left;
//         cout<<p->data;
//     }
// }
  

int main()
{
    tree t;
    t.createtree();
    t.height(t.root);

}