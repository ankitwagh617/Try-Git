#include <iostream>
using namespace std;
#define max 50
class node
{
    int data;
    node *left;
    node *right;

public:
    friend class stacks;
    friend class tree;
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
    node*s[max];
    public:
    stacks()
    {
        top = -1;
    }
    int isFull()
    {
        if(top == max-1) return 1;
        else return 0;
    }
    int isEmpty()
    {
        if(top == -1) return 1;
        else return 0;
    }
    void push(node *p)
    {
        if(isFull())
        {
            cout<<"Stack is full\n";
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
        if(isEmpty())
        {
            cout<<"Stack is empty\n";
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
    node *create_tree()
    {
        int x;
        node *temp;
        if(root == NULL)
        {
            cout<<"Enter value of root:"; 
            cin>>x;
        }
        else
        { 
            cout << "enter the value :";
            cin >> x;
        }
        if(x == -1)
        {
            return NULL;
        }
        temp = new node(x);
        if (root == NULL)
        {
            root = temp;
        }
        cout << "For left child of " << temp->data << " ";
        temp->left = create_tree();
        cout << "For right child of " << temp->data << " ";
        temp->right = create_tree();

        return temp;
    }
    void preorder(node * p)
    {
        if(p != NULL)
        {
            cout<<p->data<<" ";
            preorder(p->left);
            preorder(p->right);
        }
    }
    void call_preorder()
    {
        preorder(root);
    }
    void inorder(node * p)
    {
        if(p != NULL)
        {
            inorder(p->left);
            cout<<p->data<<" ";
            inorder(p->right);
        }
    }
    void call_inorder()
    {
        inorder(root);
    }
    void postorder(node * p)
    {
        if(p != NULL)
        {
            postorder(p->left);
            postorder(p->right);
            cout<<p->data<<" ";
        }
    }
    void call_postorder()
    {
        postorder(root);
    }
    void non_recpreorder()
    {
        node*p = root;
        stacks s;
        while(p!= NULL || !s.isEmpty())
        {
            if(p)
            {
                cout<<p->data<<" ";
                s.push(p);
                p = p->left;
            }
            else
            {
                p = s.pop();
                p = p->right;
            }
        }
    }
    void non_recpostorder()
    {
        node*p = root;
        stacks s1; stacks s2;
        s1.push(p);
        while(!s1.isEmpty())
        {
            p = s1.pop();
            s2.push(p);
            if(p->left)
            {
                s1.push(p->left);
            }
            if(p->right)
            {
                s1.push(p->right);
            }
        }
        while(!s2.isEmpty())
        {
            p = s2.pop();
            cout<<p->data<<" "; 
        }
        cout<<"\n";
    }
};

int main()
{
    tree t;
    t.create_tree();
    t.call_preorder();cout<<"\n";
    t.call_inorder();cout<<"\n";
    t.call_postorder();cout<<"\n";
    cout<<" NON-REC:";
    cout<<"\n";
    t.non_recpreorder();
    cout<<"\n";
    t.non_recpostorder();
}