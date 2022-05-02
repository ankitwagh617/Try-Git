#include <iostream>
using namespace std;

class node
{
    string word, meaning;
    node *left;
    node *right;

public:
    friend class BinarySearchTree;
    friend class stacks;
    node()
    {
        left = NULL;
        right = NULL;
    }
    node(string s1, string s2)
    {
        word = s1;
        meaning = s2;
        left = NULL;
        right = NULL;
    }
};
class stacks
{
    int top;
    node *s[50];

public:
    stacks()
    {
        top = -1;
    }
    bool isFull()
    {
        if (top == 49)
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
            cout << "Stack is full";
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
            cout << "Stack is empty";
        }
        else
        {
            p = s[top];
            top--;
        }
        return p;
    }
};
class BinarySearchTree
{
    node *root;

public:
    BinarySearchTree()
    {
        root = NULL;
    }
    void searchBST(string s1, int &count, node *&loc, node *&par)
    {
        count= 0;
        if (root == NULL)
        {
            cout << "Tree do not exist\n";
        }
        loc = NULL;
        par = NULL;
        node *ptr = root;
        while (ptr != NULL)
        {
            if (s1 == ptr->word)
            {
                loc = ptr;
                count++;
                break;
            }
            else if (s1 < ptr->word)
            {
                par = ptr;
                ptr = ptr->left;
                count++;
            }
            else
            {
                par = ptr;
                ptr = ptr->right;
                count++;
            }
        }
        if (loc == NULL)
        {
            cout << "Word not found\n";
        }
        else if (loc == ptr)
        {
            cout << "Word found\n";
        }
    }
    void loc(node *&loc, node *&par)
    {
        if (loc == NULL)
        {
            cout << endl;
        }
        else
        {
            cout << "Having meaning : " << loc->meaning << endl;
            cout << "Having parent : " << par->word << endl;
            if (loc == par->left)
            {
                cout << "And is left child of : " << par->word << endl;
            }
            else
            {
                cout << "And is right child of : " << par->word << endl;
            }
        }
    }
    void insertBST(string s1, string s2, node *&loc, node *&par)
    {
        int count = 0;
        searchBST(s1, count, loc, par);
        if (loc != NULL)
        {
            cout << "Node already exist\n";
        }
        else
        {
            node *new1 = new node(s1, s2);
            if (par == NULL)
            {
                root = new1;
            }
            else if (new1->word < par->word)
            {
                par->left = new1;
            }
            else
            {
                par->right = new1;
            }
        }
    }
    void create(node *&loc, node *&par)
    {
        int x;
        cout << "How many nodes to be inserted:";
        cin >> x;
        string s1, s2;

        for (int i = 0; i < x; i++)
        {
            cout << "\nEnter the word:";
            cin >> s1;
            cout << "Enter its meaning(use - instead of space):";
            cin >> s2;
            insertBST(s1, s2, loc, par);
        }
    }
    void inorder(node *p)
    {
        if (p != NULL)
        {
            inorder(p->left);
            cout << " -- " << p->word;
            inorder(p->right);
        }
    }
    void inorder_rec()
    {
        inorder(root);
    }
    void preorder(node *p)
    {
        if (p != NULL)
        {
            cout << " -- " << p->word;
            preorder(p->left);
            preorder(p->right);
        }
    }
    void preorder_rec()
    {
        preorder(root);
    }
    void postorder(node *p)
    {
        if (p != NULL)
        {
            postorder(p->left);
            postorder(p->right);
            cout << " -- " << p->word;
        }
    }
    void postorder_rec()
    {
        postorder(root);
    }
    void updateMeaning(int &count, node *&loc, node *&par)
    {
        string s2,s3;
        cout<<"\nEnter the word whose meaning is to be updated :";
        cin>> s2;
        searchBST(s2,count,loc,par);
        if(loc!=NULL)
        {
            s3 = loc->meaning;
            cout<<"\nEnter new meaning (use - instead of space):";
            cin>>s2;
            loc->meaning = s2;
            cout<<"Meaning updated from "<<s3<<" to "<< s2<<endl;
        }
    }
    void descending()
    {
        node *p;
        p = root;
        stacks s1, s2;
        while (p != NULL || !s1.isEmpty())
        {
            if (p != NULL)
            {
                s1.push(p);
                p = p->left;
            }
            else
            {
                p = s1.pop();
                s2.push(p);
                p = p->right;
            }
        }
        while (!s2.isEmpty())
        {
            p = s2.pop();
            cout<< " -- " << p->word ;
        }
    }
    void deleteBST1(string s1, node *&loc, node *&par)
    {
        node *child = NULL;
        if (loc->left != NULL && loc->right != NULL)
        {
            child = NULL;
        }
        else if (loc->left != NULL)
        {
            child = loc->left;
        }
        else
        {
            child = loc->right;
        }

        if (par != NULL)
        {
            if (loc == par->left)
            {
                par->left = child;
                delete loc;
            }
            else
            {
                par->right = child;
                delete loc;
            }
        }
        else
        {
            root = child;
            delete loc;
        }
    }
    void deleteBST2(string s1, node *&loc, node *&par)
    {
        node *ptr1, *ptr2;
        ptr1 = loc;
        ptr2 = loc->right;
        while (ptr2->left != NULL)
        {
            ptr1 = ptr2;
            ptr2 = ptr1->left;
        }
        loc->word = ptr2->word;
        loc->meaning = ptr2->meaning;
        deleteBST1(s1, ptr2, ptr1);
    }

    void deleteBinarySearchTree(node *&loc, node *&par)
    {
        int count = 0;
        string s1;
        cout << "\nEnter the word to be deleted:";
        cin >> s1;
        searchBST(s1,count, loc, par);
        if (loc == NULL)
        {
            cout << "Node does not exist\n";
        }
        if (loc->left != NULL && loc->right != NULL)
        {
            deleteBST2(s1, loc, par);
        }
        else
        {
            deleteBST1(s1, loc, par);
        }
        
    }
};
int main()
{
    node *loc, *par;
    int count ;
    BinarySearchTree t;
    int choice, var = 1;
    string s1, s2, s3;
    while (var == 1)
    {
        cout << "\nEnter your choice:\n1)Create BST\n2)Insert a word in BST\n3)Search a word in BST\n4)Traverse\n5)Ascending and Descending order\n6)Delete a word in BST\n7)Update meaning\n" ;
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            t.create(loc, par);
            break;
        }
        case 2:
        {
            cout << "Enter the word:";
            cin >> s1;
            cout << "Enter its meaning(use - instead of space):";
            cin >> s2;
            cout << "\nInorder traversal before addition :";
            t.inorder_rec();
            cout << endl;
            t.insertBST(s1, s2, loc, par);
            cout << "Inorder traversal after insertion :";
            t.inorder_rec();
            cout << endl;
            break;
        }
        case 3:
        {
            cout << "\nEnter the word to be searched :";
            cin >> s3;
            t.searchBST(s3,count, loc, par);
            t.loc(loc, par);
            cout<<"No. of comparisions : "<<count;
            cout<<endl;
            break;
        }
        case 4:
        {
            cout << "\nPreorder :";
            t.preorder_rec();
            cout << "\nInorder :";
            t.inorder_rec();
            cout << "\nPostorder :";
            t.postorder_rec();
            cout << endl;
            break;
        }
        case 5:
        {
            cout << "\nAscending order : ";
            t.inorder_rec();
            cout << "\nDescending order : ";
            t.descending();
            cout << endl;
            break;
        }
        case 6:
        {
            t.deleteBinarySearchTree(loc, par);
            if(loc == NULL)
            {
                cout<<endl;
            }
            else
            {
                cout<<"\nWord deleted successfully";
            }
            cout<<endl;
            break;
        }
        case 7:
        {
            t.updateMeaning(count,loc,par);
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
