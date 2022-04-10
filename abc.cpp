#include <iostream>
using namespace std;
#define MAX 50

class node
{
    int data;
    node *lc;
    node *rc;

public:
    node()
    {

        data = 0;
        lc = rc = NULL;
    }
    node(int d)
    {
        data = d;
        lc = rc = NULL;
    }

    friend class tree;
    friend class stack;
    friend class queue;
};

class queue
{

    node *dat[MAX];
    int front, rear;

public:
    queue()
    {
        front = rear = -1;
    }
    int isempty();
    int isfull();
    void enque(node *);
    node *deque();
};
int queue::isempty()
{
    if (rear == -1 || front == rear + 1)
        return 1;
    else
        return 0;
}
int queue::isfull()
{
    if (rear == MAX - 1)
        return 1;
    else
        return 0;
}

void queue::enque(node *x)
{
    if (isfull())
        cout << " Queue Overflow ";
    else if (isempty())
    {
        front = 0;
        rear = 0;
        dat[rear] = x;
    }
    else
    {
        rear++;
        dat[rear] = x;
    }
}
node *queue::deque()
{
    if (isempty())
    {
        cout << " Queue Empty ";
        return NULL;
    }
    else
    {
        node *n = dat[front];
        front++;
        return n;
    }
}

class stack
{

    node *s[20];

public:
    int top;
    stack()
    {
        top = -1;
    }
    void push(node *);
    node *pop();
    bool isempty();
    bool isfull();
    void display()
    {
        while (!isempty())
        {
            node *t = pop();
            cout << "\t" << t->data;
        }
    }
};

void stack::push(node *t)
{

    if (top == 19)
        cout << "Stack is full\n";
    else
    {
        top++;
        s[top] = t;
    }
}
bool stack::isfull()
{
    if (top == 19)
        return true;
    else
        return false;
}

node *stack::pop()
{
    node *x;
    if (top == -1)
    {
        cout << "Stack empty \n";
        return NULL;
    }
    else
    {
        x = s[top];
        top--;
        return x;
    }
}
bool stack::isempty()
{
    if (top == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

class tree
{
    stack s1;
    queue q;

public:
    node *root;
    tree()
    {

        root = NULL;
    }

    void operator=(tree &);
    node *create();
    node *create_nonrec();
    void inorder_rec(node *t);
    void preorder_rec(node *t);
    void postorder_rec(node *t);
    void inorder_nonrec(node *);
    void preorder_nonrec(node *);
    void postorder_nonrec(node *);
    void delete_tree(node *);
    void internal_nodes(node *);
    void leaf_nodes(node *);
    node *mirror(node *);
    node *copytree(node *t);
    int equal(node *, node *);
    void show()
    {
        inorder_nonrec(root);
        preorder_nonrec(root);
        postorder_nonrec(root);
    }
    void ln()
    {
        leaf_nodes(root);
    }
    void in()
    {
        internal_nodes(root);
    }
    void dt()
    {
        delete_tree(root);
        cout << "Tree Deleted Successfully\n";
    }
    node *setRoot(node *p)
    {
        root = p;
        return root;
    }
    void mirrortree()
    {

        node *n = mirror(root);
        inorder_rec(n);
        cout << endl;
    }
    void inorder()
    {
        inorder_nonrec(root);
    }
};
void tree ::operator=(tree &t1)
{

    root = copytree(t1.root);
}
node *tree::copytree(node *t1)
{
    node *n1 = NULL;
    if (t1 != NULL)
    {
        n1 = new node();

        n1->data = t1->data;
        n1->lc = copytree(t1->lc);
        n1->rc = copytree(t1->rc);
    }
    return n1;
}
int tree::equal(node *a, node *b)
{

    if (a == NULL && b == NULL)
        return 1;

    if (a != NULL && b != NULL)
    {
        return (
            a->data == b->data &&
            equal(a->lc, b->lc) &&
            equal(a->rc, b->rc));
    }
}
void tree ::preorder_nonrec(node *t)
{
    cout << "Pre order NonRec Display of Binary Tree\n";
    stack s;
    s.push(t);
    while (!s.isempty())
    {
        t = s.pop();
        cout << "\t" << t->data;
        if (t->rc != NULL)
        {
            s.push(t->rc);
        }
        if (t->lc != NULL)
        {
            s.push(t->lc);
        }
    }
    cout << endl;
}
void tree::inorder_nonrec(node *t)
{
    cout << "Inorder NonRec Display of Binary Tree\n";
    stack s;
    while (t != NULL)
    {

        s.push(t);
        t = t->lc;
    }
    while (!s.isempty())
    {
        t = s.pop();
        cout << "\t" << t->data;
        t = t->rc;
        while (t != NULL)
        {

            s.push(t);
            t = t->lc;
        }
    }
    cout << endl;
}

void tree ::postorder_nonrec(node *t)
{
    cout << "Postorder NonRec Display of Binary Tree\n";
    stack s1, s2;
    s1.push(t);
    while (!s1.isempty())
    {
        t = s1.pop();
        s2.push(t);
        if (t->lc != NULL)
            s1.push(t->lc);
        if (t->rc != NULL)
            s1.push(t->rc);
    }

    s2.display();
    cout << endl;
}

node *tree::create_nonrec()
{
    int x;
    queue q;
    node *t;
    cout << "Enter the Root\n";
    cin >> x;
    root = new node(x);

    q.enque(root);
    while (!q.isempty())
    {

        t = q.deque();
        cout << "Enter left of " << t->data << endl;
        cin >> x;
        if (x != -1)
        {
            t->lc = new node(x);
            q.enque(t->lc);
        }
        cout << "Enter Right of " << t->data << endl;
        cin >> x;
        if (x != -1)
        {
            t->rc = new node(x);
            q.enque(t->rc);
        }
    }
}

void tree::inorder_rec(node *t)
{
    if (t != NULL)
    {
        inorder_rec(t->lc);
        cout << t->data << "\t";
        inorder_rec(t->rc);
    }
}

void tree::preorder_rec(node *t)
{
    if (t != NULL)
    {
        cout << t->data << "\t";
        preorder_rec(t->lc);
        preorder_rec(t->rc);
    }
}

void tree::postorder_rec(node *t)
{
    if (t != NULL)
    {
        postorder_rec(t->lc);
        postorder_rec(t->rc);
        cout << t->data << "\t";
    }
}

node *tree::create()
{
    int x;
    cout << "Enter the data or -1 to stop \n";
    cin >> x;
    if (x == -1)
    {
        return NULL;
    }
    else
    {
        node *p = new node;
        p->data = x;
        cout << "Enter the left child of " << x << endl;
        p->lc = create();
        cout << "Enter the Right child of " << x << endl;
        p->rc = create();
        return p;
    }
}
void tree::delete_tree(node *t)
{
    if (t != NULL)
    {
        delete_tree(t->lc);
        delete_tree(t->rc);
        delete t;
    }
}
void tree::leaf_nodes(node *t)
{
    if (t == NULL)
    {
        return;
    }
    if (t->lc == NULL && t->rc == NULL)
    {
        cout << t->data << " ";
        return;
    }
    if (t->lc != NULL)
    {
        leaf_nodes(t->lc);
    }
    if (t->rc != NULL)
    {
        leaf_nodes(t->rc);
    }
}
void tree::internal_nodes(node *t)
{

    if (t != NULL)
    {
        if (t->lc != NULL || t->rc != NULL)
        {
            cout << t->data << " ";
        }
        if (t->lc != NULL)
            ;
        internal_nodes(t->lc);
        if (t->rc != NULL)
            ;
        internal_nodes(t->rc);
    }
}
node *tree::mirror(node *t)
{
    node *p = NULL;
    if (t != NULL)
    {
        p = new node();
        p->data = t->data;
        p->lc = mirror(t->rc);
        p->rc = mirror(t->lc);
    }
    // inorder_rec(p);
    return p;
}

int main()
{
    int ch, c;
    node *p, *q;
    stack s1, s2;
    tree y, t1, t2, t3;
    do
    {
        cout << "Enter Choice\n1.Create and Traversal\n2.Leaf Nodes\n3.Internal Nodes\n4.Mirror of Tree\n5.Deletion of Tree\n6.Copy of tree\n7.Check Equal\n8.EXIT\n";
        cin >> c;
        switch (c)
        {
        case 1:
        {
            cout << "Enter Choice\nCreation and Traversal of Binary tree by\n1.Recurssion\n2.Non-Recurssion\n";
            cin >> ch;
            switch (ch)
            {
            case 1:
            {
                cout << "Creating Binary Tree\n";
                p = y.create();
                y.setRoot(p);
                cout << "\nInorder Display of Binary Tree\n";
                y.inorder_rec(p);
                cout << "\nPreorder Display of Binary Tree\n";
                y.preorder_rec(p);
                cout << "\nPostorder Display of Binary Tree\n";
                y.postorder_rec(p);
                break;
            }
            case 2:
            {
                cout << "Creating Binary Tree\n";
                p = y.create_nonrec();
                y.show();
                break;
            }
            default:
                cout << "Wrong choice\n";
            }
            break;
        }
        case 2:
            y.ln();
            break;
        case 3:
            y.in();
            break;
        case 4:
            y.mirrortree();
            break;
        case 5:
            y.dt();
            break;
        case 6:
            t1 = y;
            cout << "Copying Tree\n";
            t1.inorder();
            break;
        case 7:
        {
            p = t3.create();
            t3.setRoot(p);
            cout << "Enter for second tree\n";
            q = t2.create();
            t2.setRoot(q);

            if (t3.equal(p, q))
            {
                cout << "Both trees are equal\n";
            }
            else
                cout << "Both trees not Equal\n";
            break;
        }
        case 8:
            break;
        }
    } while (c != 8);

    return 0;
}