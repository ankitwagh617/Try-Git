#include <bits/stdc++.h>
using namespace std;
#define MAX 50
class node
{
    int data;
    node *left;
    node *right;

public:
    friend class tree;
    friend class stacks;
    friend class queues;
    node()
    {
        data = 0;
        left = right = NULL;
    }
    node(int x)
    {
        data = x;
        left = right = NULL;
    }
};
class stacks
{
    int top;
    node *s[MAX];

public:
    stacks()
    {
        top = -1;
    }
    bool isFull()
    {
        if (top == MAX - 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool isEmpty()
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
    void push(node *p)
    {
        if (isFull())
        {
            cout << "Stack is full\n";
        }
        else
        {
            top++;
            s[top] = p;
        }
    }
    node *pop()
    {
        node *p;
        if (isEmpty())
        {
            cout << "Stack is empty\n";
        }
        else
        {
            p = s[top];
            top--;
        }
        return p;
    }
};

class queues
{
    int front, rear;
    node *q[MAX];

public:
    queues()
    {
        front = rear = -1;
    }
    bool is_full()
    {
        if (rear == MAX - 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool is_Empty()
    {
        if (rear == -1 || front > rear)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void enqueue(node *p)
    {
        if (is_full())
        {
            cout << "Queue is full\n";
        }
        else if (is_Empty())
        {
            front = 0;
            rear = 0;
            q[rear] = p;
        }
        else
        {
            rear++;
            q[rear] = p;
        }
    }

    node *dequeue()
    {
        node *p;
        if (is_Empty())
        {
            cout << "Queue is empty\n";
        }
        else
        {
            p = q[front];
            front++;
        }
        return p;
    }
};

class tree
{
    node *root;

public:
    tree()
    {
        root = NULL;
    }
    void Rec_preorder()
    {
        preorder_rec(root);
    }
    void Rec_inorder()
    {
        inorder_rec(root);
    }
    void Rec_postorder()
    {
        postorder_rec(root);
    }
    void L_node()
    {
        leaf_node(root);
    }
    void I_node()
    {
        internal_node(root);
    }
    void deletetree()
    {
        if (root == NULL)
        {
            cout << "\nFirst create tree\n";
        }
        else
        {
            delete1(root);
            cout << "\nTree deleted successfully!!\n";
        }
    }
    int tree_height()
    {
        int x = height1(root);
        return x;
    }
    int count_leaf(node *p)
    {
        if (p == NULL)
        {
            return 0;
        }
        if (p->left == NULL && p->right == NULL)
        {
            return 1;
        }
        return count_leaf(p->left) + count_leaf(p->right);
    }
    int total_leafNodes()
    {
        int x = count_leaf(root);
        return x;
    }
    int count_internal(node *p)
    {
        int count = 0;
        if (p->left != NULL || p->right != NULL)
        {
            count = 1;
            if (p->left != NULL)
            {
                count += count_internal(p->left);
            }
            if (p->right != NULL)
            {
                count += count_internal(p->right);
            }
        }
        return count;
    }
    int total_internalNodes()
    {
        int x = count_internal(root);
        return x;
    }
    void operator=(tree &t);
    int height1(node *p);
    void preorder_rec(node *p);
    void inorder_rec(node *p);
    void postorder_rec(node *p);
    void preorder_nonrec();
    void inorder_nonrec();
    void postorder_nonrec();
    void levelorder();
    node *mirror(node *p);
    void mirrortree();
    node *delete1(node *p);
    void leaf_node(node *p);
    void internal_node(node *p);
    node *copytree(node *p);
    void create_nonrec()
    {
        int x;
        queues q1;
        node *t, *a;
        cout << "Enter the value of root-->>";
        cin >> x;
        root = new node(x);
        q1.enqueue(root);
        while (!q1.is_Empty())
        {
            t = q1.dequeue();
            cout << "Enter the left child " << t->data << "-->>";
            cin >> x;
            if (x != -1)
            {
                a = new node(x);
                a->left = a->right = NULL;
                t->left = a;
                q1.enqueue(a);
            }
            cout << "Enter the right child " << t->data << "-->>";
            cin >> x;
            if (x != -1)
            {
                a = new node(x);
                a->left = a->right = NULL;
                t->right = a;
                q1.enqueue(a);
            }
        }
    }
};

void tree::preorder_rec(node *p)
{
    if (p != NULL)
    {
        cout << p->data << " ";
        preorder_rec(p->left);
        preorder_rec(p->right);
    }
}

void tree ::inorder_rec(node *p)
{
    if (p != NULL)
    {
        inorder_rec(p->left);
        cout << p->data << " ";
        inorder_rec(p->right);
    }
}

void tree::postorder_rec(node *p)
{
    if (p != NULL)
    {
        postorder_rec(p->left);
        postorder_rec(p->right);
        cout << p->data << " ";
    }
}

void tree::preorder_nonrec()
{
    node *p;
    p = root;
    stacks st;
    while (p != NULL || !st.isEmpty())
    {
        if (p != NULL)
        {
            cout << p->data << " ";
            st.push(p);
            p = p->left;
        }
        else
        {
            p = st.pop();
            p = p->right;
        }
    }
}

void tree::inorder_nonrec()
{
    node *p;
    p = root;
    stacks st;
    while (p != NULL || !st.isEmpty())
    {
        if (p != NULL)
        {
            st.push(p);
            p = p->left;
        }
        else
        {
            p = st.pop();
            cout << p->data << " ";
            p = p->right;
        }
    }
}

void tree::postorder_nonrec()
{
    node *p;
    p = root;
    stacks st1, st2;
    st1.push(p);
    while (!st1.isEmpty())
    {
        p = st1.pop();
        st2.push(p);
        if (p->left != NULL)
            st1.push(p->left);
        if (p->right != NULL)
            st1.push(p->right);
    }
    while (!st2.isEmpty())
    {
        p = st2.pop();
        cout << p->data << " ";
    }
}
void tree::levelorder()
{
    node *p;
    p = root;
    queues q1;
    q1.enqueue(p);
    while (!q1.is_Empty())
    {
        p = q1.dequeue();
        cout << p->data << " ";
        if (p->left != NULL)
        {
            q1.enqueue(p->left);
        }
        if (p->right != NULL)
        {
            q1.enqueue(p->right);
        }
    }
}

node *tree::delete1(node *p)
{
    if (p != NULL)
    {
        delete1(p->left);
        delete1(p->right);
        delete p;
    }
    return p;
}

void tree::leaf_node(node *p)
{
    if (p == NULL)
    {
        return;
    }
    if (p->left == NULL && p->right == NULL)
    {
        cout << " - " << p->data;
    }
    if (p->left != NULL)
    {
        leaf_node(p->left);
    }
    if (p->right != NULL)
    {
        leaf_node(p->right);
    }
}

void tree::internal_node(node *p)
{
    if (p == NULL)
    {
        return;
    }
    if (p->left != NULL || p->right != NULL)
    {
        cout << " - " << p->data;
    }
    if (p->left != NULL)
    {
        internal_node(p->left);
    }
    if (p->right != NULL)
    {
        internal_node(p->right);
    }
}

node *tree::mirror(node *p)
{
    node *m1 = NULL;
    if (p != NULL)
    {
        m1 = new node();
        m1->data = p->data;
        m1->left = mirror(p->right);
        m1->right = mirror(p->left);
    }
    return m1;
}

void tree::mirrortree()
{
    node *n = mirror(root);
    inorder_rec(n);
}

void tree ::operator=(tree &t)
{

    root = copytree(t.root);
}

node *tree::copytree(node *p)
{
    node *n1 = NULL;
    if (p != NULL)
    {
        n1 = new node();

        n1->data = p->data;
        n1->left = copytree(p->left);
        n1->right = copytree(p->right);
    }
    return n1;
}

int tree::height1(node *p)
{
    int h1 = 0, h2 = 0;
    if (p == NULL)
    {
        return -1;
    }
    if (p->left == NULL && p->right == NULL)
    {
        return 0;
    }
    h1 = height1(p->left);
    h2 = height1(p->right);
    if (h1 > h2)
    {
        return h1 + 1;
    }
    else
    {
        return h2 + 1;
    }
}

int main()
{

    int ch, var = 1;
    tree t, t1, t2, t3, t4;
    while (var == 1)
    {
        cout << "\nEnter Choice:\n1.Create and Traversal\n2.Leaf Nodes & Internal Nodes\n3.Mirror of Tree";
        cout << "\n4.Deletion of Tree\n5.Copy of tree\n6.Height\n";
        cin >> ch;
        switch (ch)
        {
        case 1:
        {
            cout << "Creating Binary Tree Non-rec:\n";
            t1.create_nonrec();
            cout << "\nRecursive -->>" << endl;
            cout << "Preorder:";
            t1.Rec_preorder();
            cout << "\nInorder:";
            t1.Rec_inorder();
            cout << "\nPostorder:";
            t1.Rec_postorder();
            cout << endl;
            cout << "\nNon-recursive-->>" << endl;
            cout << "Preorder:";
            t1.preorder_nonrec();
            cout << "\nInorder:";
            t1.inorder_nonrec();
            cout << "\nPostorder:";
            t1.postorder_nonrec();
            cout << endl;
            cout << "\nLevelorder:";
            t1.levelorder();
            cout << endl;
            break;
        }
        case 2:
        {
            cout << "\nInternal nodes count:" << t1.total_internalNodes() << " which are:";
            t1.I_node();
            cout << "\nLeaf nodes count:" << t1.total_leafNodes() << " which are:";
            t1.L_node();
            cout << endl;
            break;
        }
        case 3:
        {
            t3.create_nonrec();
            cout << "\nInorder traversal before:";
            t3.inorder_nonrec();
            cout << endl
                 << "Inorder traversal after mirror:";
            t3.mirrortree();
            cout << endl;
            break;
        }
        case 4:
        {
            t1.deletetree();
            break;
        }
        case 5:
        {
            t = t1;
            cout << "\nInorder of copied tree:";
            t.inorder_nonrec();
            break;
        }
        case 6:
        {
            t2.create_nonrec();
            cout << "\nHeight of the tree is:" << t2.tree_height();
            break;
        }
        default:
        {
            cout << "\nEnter valid choice!\n";
            break;
        }
        }
        cout << "\nDo you want to continue (0/1): ";
        cin >> var;
    }
}
