#include <bits/stdc++.h>
using namespace std;

class node
{
    int data;
    node *next;

public:
    friend class List;
    node()
    {
        data = 0;
        node *next = NULL;
    }
    node(int d)
    {
        data = d;
        node *next = NULL;
    }
};
class List
{
    node *head;

public:
    List()
    {
        head = NULL;
    }
    void insertAtTail(int d)
    {
        node *n = new node;
        n->data = d;
        n->next = NULL;
        if (head == NULL)
        {
            n->next = head;
            head = n;
        }
        else
        {
            node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = n;
        }
    }
    void insertAtHead(int d)
    {
        node *n = new node;
        n->data = d;
        n->next = NULL;
        n->next = head;
        head = n;
    }
    void display()
    {
        node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
    void additionOddPlaces()
    {
        int count = 1;
        int sum = 0;
        node *temp = head;
        while (temp != NULL)
        {
            if (count % 2 != 0)
            {
                sum = sum + temp->data;
            }
            temp = temp->next;
            count++;
        }
        cout << "Sum of numbers at odd places is:" << sum << endl;
    }
    void additionEvenPlaces()
    {
        int count = 1;
        int sum1 = 0;
        node *temp = head;
        while (temp != NULL)
        {
            if (count % 2 == 0)
            {
                sum1 = sum1 + temp->data;
            }
            temp = temp->next;
            count++;
        }
        cout << "Sum of numbers at even places is:" << sum1 << endl;
    }
    void additionOfPrime()
    {
        node *temp = head;
        int sum2 = 0;
        while (temp != NULL)
        {
            int count = 0;
            for (int i = 2; i < temp->data; i++)
            {
                if (temp->data % i == 0)
                {
                    count++;
                }
            }
            if (count == 0)
            {
                sum2 = sum2 + temp->data;
            }
            temp = temp->next;
        }

        cout << "Addition of prime numbers is:" << sum2 << endl;
    }
    void additionOfNonPrime()
    {
        node *temp = head;
        int sum3 = 0;
        while (temp != NULL)
        {
            int count = 0;
            for (int i = 2; i < temp->data; i++)
            {
                if (temp->data % i == 0)
                {
                    count++;
                }
            }
            if (count != 0)
            {
                sum3 = sum3 + temp->data;
            }
            temp = temp->next;
        }

        cout << "Addition of non-prime numbers is:" << sum3 << endl;
    }
    void deleteNode(node *del)
    {
        node *temp = head;
        if (head == del)
        {
            head = del->next;
        }
        else
        {
            while (temp->next != del)
            {
                temp = temp->next;
            }
            temp->next = del->next;
        }

        free(del);
        return;
    }
    bool isPrime(int n)
    {
        if (n <= 1)
            return false;
        if (n <= 3)
            return true;
        if (n % 2 == 0 || n % 3 == 0)
            return false;

        for (int i = 5; i * i <= n; i = i + 6)
            if (n % i == 0 || n % (i + 2) == 0)
                return false;

        return true;
    }
    void deletePrime()
    {
        node *ptr = head;
        node *nxt;
        while (ptr != NULL)
        {
            nxt = ptr->next;
            if (isPrime(ptr->data))
            {
                deleteNode(ptr);
            }
            ptr = nxt;
        }
    }
};

int main()
{
    List l;
    char c = 'y';
    while (c == 'y')
    {
        int n, sum = 0;
        cout << "Enter the number:";
        cin >> n;
        int a = n;
        while (n != 0)
        {
            int m = n % 10;
            n = (n - m) / 10;
            sum = sum + m;
        }
        if (sum % 2 == 0)
        {
            l.insertAtHead(a);
            cout << "Insertion at head completed!\n";
        }
        else
        {
            l.insertAtTail(a);
            cout << "Insertion at tail completed!\n";
        }
        cout << "\nDo you want to continue(y/n):";
        cin >> c;
        cout << endl;
    }
    l.display();
    l.additionOddPlaces();
    l.additionEvenPlaces();
    l.additionOfPrime();
    l.additionOfNonPrime();
    l.deletePrime();
    cout << endl;
    cout << "Linked list after deletion of prime numbers:\n";
    l.display();
}
