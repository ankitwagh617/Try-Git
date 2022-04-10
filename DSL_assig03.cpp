#include <iostream>
using namespace std;

class node
{
    int data;
    node *left;
    node *right;
    bool lbit, rbit;
    friend class TBT;

public:
    node()
    {
        data = 0;
        left = right = NULL;
        lbit = rbit = NULL;
    }
    node(int x)
    {
        data = x;
        left = right = NULL;
        lbit = rbit = NULL;
    }
};

class TBT
{
    node *root;
    node *header;
public:
    TBT()
    {
        root = NULL;
        header = NULL;
    }
    void searchTBT(node* &loc,node* &par,int &count)
    {
        int key;
        cout<<"\nEnter the key to be searched :";
        cin>>key;
        if(root == NULL)
        {
            cout<<"\nKey not found";
        }
        else
        {
            node*ptr = root;
            while(1)
            {
                if(ptr->data == key)
                {
                    count++;
                    loc = ptr;
                    cout<<"\nKey found";
                    break;
                }
                else if(ptr->data > key)
                {
                    count++;
                    if(ptr->lbit != 0)
                    {
                        par = ptr;
                        ptr = ptr->left;
                    }
                    else
                    {
                        cout<<"\nKey not found";
                        break;
                    }

                }
                else
                {
                    count++;
                    if(ptr->rbit != 0)
                    {
                        par = ptr;
                        ptr = ptr->right;
                    }
                    else
                    {
                        cout<<"\nKey not found";
                        break;   
                    }
                }
            }
        }
    }
    void loc(node* &loc,node* &par,int &count)
    {  
        cout<<"\nNumber of comparisions are :"<<count;
    }
    void insertTBT(int x)
    {
        if (root == NULL)
        {
            header = new node(-99);
            header->right = header;
            root = new node(x);
            root->left = header;
            root->right = header;
            header->left = root;
        }
        else
        {
            node *ptr = root;
            node *temp = new node(x);
            while (1)
            {
                if (ptr->data > x)
                {
                    if (ptr->lbit != 0)
                    {
                        ptr = ptr->left;
                    }
                    else
                    {
                        temp->left = ptr->left;
                        temp->right = ptr;
                        ptr->lbit = 1;
                        ptr->left = temp;
                        break;
                    }
                }
                else
                {
                    if (ptr->rbit != 0)
                    {
                        ptr = ptr->right;
                    }
                    else
                    {
                        temp->right = ptr->right;
                        temp->left = ptr;
                        ptr->rbit = 1;
                        ptr->right = temp;
                        break;
                    }
                }
            }
        }
    }
    void createTBT()
    {
        int x, key;
        cout << "\nHow many node you want to insert :";
        cin >> x;
        for (int i = 0; i < x; i++)
        {
            cout << "\nEnter the value of key :";
            cin >> key;
            insertTBT(key);
            cout << "Key inserted successfully" << endl;
        }
    }
    void inorder()
    {
        node *p = root;
        while (p->lbit != 0)
        {
            p = p->left;
        }
        while (p != header)
        {
            cout << " -- " << p->data;
            if (p->rbit != 0)
            {
                p = p->right;
                while (p->lbit != 0)
                {
                    p = p->left;
                }
            }
            else
            {
                p = p->right;
            }
        }
    }
    void preorder()
    {
        int flag =0;
        node *p = root;
        while (p != header)
        {
            if(flag == 0){
            cout << " -- " << p->data;
            }
            if (p->lbit == 1 && flag == 0)
            {
                p = p->left;
            }
            else
            {
                if(p->rbit == 1 )
                {
                    flag =0;
                }
                else
                {
                    flag = 1;
                }
                p = p->right;
            }
        }
    }
    void deleteTBT(node* &loc,node* &par)
    {
    	int count =0;
        searchTBT(loc,par,count);
    	if(loc->rbit == 0 && loc->rbit == 0)
    	{
    		deleteTBTnochild(loc,par);
    	}
    	if(loc->rbit == 1 && loc->rbit == 0)
    	{
    		deletTBToneleftchild(loc,par);
    	}
    	if(loc->rbit == 0 && loc->rbit == 1)
    	{
    		deletTBTonerightchild(loc,par);
    	}
    	if(loc->rbit == 1 && loc->rbit == 1)
    	{
    		deleteTBTtwochild(loc,par);
    	}
    }
    void deleteTBTnochild(node* &loc,node* &par)
    {
    	if(par->left == loc)
    	{
    		par->left = loc->left;
    		par->lbit = 0;
    	}
    	else
    	{
    		par->right = loc->right;
    		par->rbit = 0;
    	}
    	delete(loc);
    }
    void deletTBToneleftchild(node* &loc,node* &par)
    {
    	node*child = loc->left;
    	if(par->left == loc)
    	{
    		par->left = child;
    	}
    	else
    	{
    		par->right = child;
    	}
    	while(child->rbit == 1)
    	{ 
    		child = child->right;
    	}
    	child->right = loc->right;
    	delete(loc);
    }
    void deletTBTonerightchild(node* &loc,node* &par)
    {
    	node*child = loc->right;
    	if(par->left == loc)
    	{
    		par->left = child;
    	}
    	else
    	{
    		par->right = child;
    	}
    	while(child->lbit == 0)
    	{
    		child = child->left;
    	}
    	child->left = loc->left;
    	delete(loc);

    }
    void deleteTBTtwochild(node* &loc,node* &par)
    {
    	node *ptr1, *ptr2;
        ptr1 = loc;
        ptr2 = loc->right;
    	while(ptr2->lbit != 0)
    	{
    		ptr1 = ptr2;
            ptr2 = ptr1->left;
    	}
    	loc->data = ptr2->data;
        deleteTBTnochild(ptr2,ptr1);
    }
};
int main()
{
    int count = 0, var = 1;
    node *loc, *par;
    TBT t;
    int choice, key;
    while (var == 1)
    {
        cout << "\n1)Create TBT\n2)Search a key\n3)Insert new key\n4)Traverse in TBT\n5)Delete a key from TBT\nEnter your choice:";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            t.createTBT();
            break;
        }
        case 2:
        {
            t.searchTBT(loc,par,count);
            t.loc(loc,par,count);
            loc = NULL;
            count = 0;
            break;
        }
        case 3:
        {
            cout << "\nEnter the key to be inserted :";
            cin >> key;
            cout << "\nKey inserted successfully";
            cout << "\nInorder traversal before insertion :";
            t.inorder();
            t.insertTBT(key);
            cout << "\nInorder traversal after insertion :";
            t.inorder();
            break;
        }
        case 4:
        {
            cout << "\nPreorder traversal :";
            t.preorder();
            cout << "\nInorder traversal :";
            t.inorder();
            break;
        }
        case 5:
        {
        	cout << "\nInorder traversal before deletion :";
        	t.inorder();
        	t.deleteTBT(loc, par);
        	cout << "\nInorder traversal after deletion :";
        	t.inorder();
            break;
        }
        default:
        {
            cout << "\nEnter valid chioce";
            break;
        }
        }
        cout << "\n\nDo you want to continue (0/1): ";
        cin >> var;
    }
}

