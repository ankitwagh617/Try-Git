//============================================================================
// Name        : assignment.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#define size 9

class hashEntry
{
    string word, meaning;
    hashEntry *next;

public:
    friend class hashTable;
    hashEntry()
    {
        word = "";
        meaning = "";
        next = NULL;
    }
    hashEntry(string w, string m)
    {
        word = w;
        meaning = m;
        next = NULL;
    }
};
class hashTable
{
    hashEntry *ht[size];

public:
    hashTable()
    {
        for (int i = 0; i < size; i++)
        {
            ht[i] = NULL;
        }
    }
    int hashFunction(string s)
    {
        int sum = 0;
        for (int i = 0; i < s.length(); i++)
        {
            sum = sum + s[i];
        }
        return (sum % size);
    }
    void insert()
    {
        hashEntry h;
        int var = 1;
        while (var == 1)
        {
            cout << "\nEnter word :";
            cin >> h.word;
            cout << "Enter meaning :";
            cin >> h.meaning;
            int hash_index = hashFunction(h.word);
            if (ht[hash_index] == NULL)
            {
                ht[hash_index] = new hashEntry(h.word, h.meaning);
                cout << "\nTelephone number inserted successfully";
            }
            else
            {
                hashEntry *temp = ht[hash_index];
                while (temp->next != NULL)
                {
                    temp = temp->next;
                }
                temp->next = new hashEntry(h.word, h.meaning);
            }
            cout << "\nDo you want to continue (0/1):";
            cin >> var;
        }
    }
    void display()
    {
        cout << "Index\n";
        for (int i = 0; i < size; i++)
        {
            if (ht[i] == NULL)
            {
                cout << i << endl;
            }
            else
            {
                cout << i << " ";
                while (ht[i] != NULL)
                {
                    cout << ht[i]->word << "=" << ht[i]->meaning << "--->>";
                    ht[i] = ht[i]->next;
                }
                cout << "NULL";
                cout << "\n";
            }
        }
    }
    void search()
    {
        hashEntry h;
        cout << "\nEnter word :";
        cin >> h.word;
        int hash_index = hashFunction(h.word);
        hashEntry *temp = ht[hash_index];
        while (temp != NULL)
        {
            if (temp->word == h.word)
            {
                cout << "Word found at index" << hash_index << "\n";
                break;
            }
            else
            {
                temp = temp->next;
                if (temp->next == NULL)
                {
                    cout << "\nWord not found";
                    break;
                }
            }
        }
    }
    void delete1()
    {
        hashEntry h;
        cout << "Enter word to be deleted:";
        cin >> h.word;
        int hash_index = hashFunction(h.word);
        if (ht[hash_index] == NULL)
        {
            cout << "\nWord not found";
        }
        else
        {
            hashEntry *temp = ht[hash_index];
            hashEntry *toDelete;
            if (temp->word == h.word)
            {
                toDelete = temp;
                ht[hash_index] = temp->next;
                delete toDelete;
            }
            else
            {
                while (temp->next->word != h.word)
                {
                    temp = temp->next;
                }
                toDelete = temp->next;
                delete toDelete;
            }
        }
    }
};

int main()
{
    hashTable h1;
    int var = 1;
    int a;
    while (var == 1)
    {
        cout << "\nEnter your choice:\n1)Insert\n2)Display\n3)Search\n4)Delete\n";
        cin >> a;
        switch (a)
        {
        case 1:
        {
            h1.insert();
            break;
        }
        case 2:
        {
            h1.display();
            break;
        }
        case 3:
        {
            h1.search();
            break;
        }
        case 4:
        {
            h1.delete1();
            break;
        }
        }
        cout << "\nDo you want to continue(0/1):";
        cin >> var;
    }
}
