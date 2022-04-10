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

class tree
{
    node *root;

public:
    tree()
    {
        root = NULL;
    }
    node *create_tree_rec()
    {
        int val;
        cout << "\nEnter the value :";
        cin >> val;
        if (val == -1) 
        {
            return NULL;
        }
        node* temp;
        temp = new node(val);
        if(root == NULL){
            root = temp;
        } 
        cout << "\nFor left child of "<< temp->data <<" (-1 if no left child):";
        temp->left = create_tree_rec();
        cout << "\nFor right child of "<< temp->data <<" (-1 if no left child):";
        temp->right = create_tree_rec();
        return temp;
    }
    void preorder_nonrec()
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

    void inorder_nonrec()
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

    void postorder_nonrec()
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
};

int main()
{
    tree t;
    t.create_tree_rec();
    t.inorder_nonrec();
    cout<<endl;
    t.preorder_nonrec();
    cout<<endl;
    t.postorder_nonrec();
}