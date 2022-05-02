#include <iostream>
using namespace std;
#define int long long
#define size 10

class hashEntry
{
    int telephoneNo;
    string name;

public:
    friend class hashTable;
    hashEntry()
    {
        telephoneNo = 0;
        name = "";
    }
    hashEntry(int x, string y)
    {
        telephoneNo = x;
        name = y;
    }
};

class hashTable
{
    hashEntry ht[size];

public:
    hashTable()
    {
        for (int i = 0; i < size; i++)
        {
            ht[i].telephoneNo = 0;
            ht[i].name = "";
        }
    }
    int hashfunction(int key)
    {
        return (key % size);
    }
    void insert_without_replacement()
    {
        int var = 1;
        while (var == 1)
        {
            hashEntry h;
            cout << "\nEnter the telephone key to be inserted : ";
            cin >> h.telephoneNo;
            cout << "Enter the name : ";
            cin >> h.name;
            int hash_index = hashfunction(h.telephoneNo);
            if (ht[hash_index].telephoneNo == 0)
            {
                ht[hash_index] = h;
                cout << "Telephone number inserted successfully " << hash_index << " index of hashtable"
                     << "\n";
            }
            else if (ht[hash_index].telephoneNo == h.telephoneNo)
            {
                cout << "Number already exist\n";
            }
            else
            {
                int i = hash_index + 1;
                while (1)
                {
                    if (ht[i].telephoneNo == h.telephoneNo)
                    {
                        cout << "Telephone number already exist";
                        break;
                    }
                    if (i == size)
                    {
                        i = 0;
                    }
                    if (ht[i].telephoneNo == 0)
                    {
                        ht[i] = h;
                        cout << "Telephone number inserted successfully at " << i << " index of hashtable"
                             << "\n";
                        break;
                    }
                    if (i == hash_index)
                    {
                        cout << "Table is full\n";
                        break;
                    }
                    i++;
                }
            }
            cout << "\nDo you want to continue adding telephone numbers (1/0):";
            cin >> var;
        }
    }
    void insert_with_replacement()
    {
        int var = 1;
        while (var == 1)
        {
            hashEntry h;
            cout << "\nEnter the telephone key to be inserted : ";
            cin >> h.telephoneNo;
            cout << "Enter the name : ";
            cin >> h.name;
            int hash_index = hashfunction(h.telephoneNo);
            if (ht[hash_index].telephoneNo == 0)
            {
                ht[hash_index] = h;
                cout << "Telephone number inserted successfully " << hash_index << " index of hash table"
                     << "\n";
            }
            else if (ht[hash_index].telephoneNo == h.telephoneNo)
            {
                cout << "Number already exist\n";
            }
            else
            {
                int x = ht[hash_index].telephoneNo;
                string s = ht[hash_index].name;
                if (x % size == hash_index)
                {
                    int i = hash_index + 1;
                    while (1)
                    {
                        if (ht[i].telephoneNo == h.telephoneNo)
                        {
                            cout << "Telephone number already exist";
                            break;
                        }
                        if (i == size)
                        {
                            i = 0;
                        }
                        if (ht[i].telephoneNo == 0)
                        {
                            ht[i] = h;
                            cout << "Telephone number inserted successfully at " << i << " index of hashtable"
                                 << "\n";
                            break;
                        }
                        if (i == hash_index)
                        {
                            cout << "Table is full\n";
                            break;
                        }
                        i++;
                    }
                }
                else
                {
                    ht[hash_index] = h;
                    int i = hash_index + 1;
                    while (1)
                    {
                        if (i == size)
                        {
                            i = 0;
                        }
                        if (ht[i].telephoneNo == 0)
                        {
                            ht[i].telephoneNo = x;
                            ht[i].name = s;
                            cout << "Telephone number inserted successfully at " << hash_index << " index of hashtable"
                                 << "\n";
                            break;
                        }
                        if (i == hash_index)
                        {
                            cout << "Table is full\n";
                            break;
                        }
                        i++;
                    }
                }
            }
            cout << "\nDo you want to continue adding telephone numbers (1/0):";
            cin >> var;
        }
    }
    void display()
    {
        cout << "\n";
        for (int i = 0; i < size; i++)
        {
            cout << i << ".  " << ht[i].telephoneNo << "         " << ht[i].name << "\n";
        }
    }
    void delete_key()
    {
        int x;
        cout << "\nEnter the telephone key to be deleted : ";
        cin >> x;
        int hash_index = hashfunction(x);
        if (ht[hash_index].telephoneNo == x)
        {
            cout << "Telephone key found at " << hash_index << " index"
                 << "\n";
            cout << "Having name : " << ht[hash_index].name;
            ht[hash_index].telephoneNo = 0;
            ht[hash_index].name = "";
            cout << "\nTelephone key deleted successfully";
            cout << "\n";
        }
        else
        {
            int i = hash_index + 1;
            while (1)
            {
                if (i == size)
                {
                    i = 0;
                }
                if (ht[i].telephoneNo == x)
                {
                    cout << "Telephone key found at " << i << " index "
                         << "\n";
                    cout << "Having name : " << ht[i].name;
                    ht[i].telephoneNo = 0;
                    ht[i].name = "";
                    cout << "\nTelephone key deleted successfully";
                    cout << "\n";
                    break;
                }
                if (i == hash_index)
                {
                    cout << "Telephone key not found\n";
                    break;
                }
                i++;
            }
        }
    }
    void search()
    {
        int count = 1;
        int x;
        cout << "\nEnter the telephone key to be searched : ";
        cin >> x;
        int hash_index = hashfunction(x);
        if (ht[hash_index].telephoneNo == x)
        {
            cout << "Telephone key found at " << hash_index << " index"
                 << "\n";
            cout << "Having name : " << ht[hash_index].name;
            cout << "\nNumber of comparisons:" << count;
            cout << "\n";
        }
        else
        {
            int i = hash_index + 1;
            while (1)
            {
                if (i == size)
                {
                    i = 0;
                }
                if (ht[i].telephoneNo == x)
                {
                    cout << "Telephone key found at " << i << " index "
                         << "\n";
                    cout << "Having name : " << ht[i].name;
                    count++;
                    cout << "\nNumber of comparisons:" << count;
                    cout << "\n";
                    break;
                }
                if (i == hash_index)
                {
                    cout << "Telephone key not found\n";
                    break;
                }
                i++;
                count++;
            }
        }
    }
};

int32_t main()
{
    hashTable h1;
    int var = 1;
    int choice, choice1;
    while (var == 1)
    {
        cout << "Enter your choice:\n1)Insert\n2)Search a key\n3)Display table\n4)Delete a key\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            cout << "Enter your choice:\n1)Insert without replacement\n2)Insert with replacement\n";
            cin >> choice1;
            switch (choice1)
            {
            case 1:
            {
                h1.insert_without_replacement();
                break;
            }
            case 2:
            {
                h1.insert_with_replacement();
                break;
            }
            }
            break;
        }
        case 2:
        {
            h1.search();
            break;
        }
        case 3:
        {
            h1.display();
            break;
        }
        case 4:
        {
            h1.delete_key();
            break;
        }
        default:
        {
            cout << "\nEnter valid chioce:";
            break;
        }
        }
        cout << "\nDo you want to continue (1/0):";
        cin >> var;
    }
}
