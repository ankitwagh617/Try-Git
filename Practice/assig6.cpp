/**********************************************************
 *
 * Author: Shivani Yadav
 * Roll No: 21473
 * Experiment 06: Graph Array
 *
 ***********************************************************/

#include <iostream>
using namespace std;
#define size 10
class Graph
{
    int g[size][size];
    int v1, v2;
    int visit[size];

public:
    int n;
    Graph();
    void create();
    void BFS(int);
    void recursiveDFS(int);
    void iterativeDFS(int);
    void display();
    friend class Queuee;
};
class Queuee
{
    int front, rear;
    int a[size];

public:
    Queuee()
    {
        front = -1;
        rear = -1;
    }

    void push(int data);
    int pop();
    int top();
    bool isEmpty();
    bool isFull();
};
bool Queuee::isFull()
{
    if (front == 0 && rear == size - 1)
    {
        return true;
    }
    return false;
}

bool Queuee::isEmpty()
{
    if (front == -1 || front > rear)
    {
        return true;
    }
    return false;
}

void Queuee::push(int data)
{
    if (isFull())
    {
        cout << "Queue is Full No more data can be inserted!!\n";
    }
    else
    {
        rear++;
        a[rear] = data;

        if (front == -1)
        {
            front++;
        }
    }
}

int Queuee::pop()
{
    if (isEmpty())
    {
        cout << "Queue is Empty!\n";
        return -1;
    }
    else
    {
        return front++;
    }
}

int Queuee::top()
{
    if (isEmpty())
    {
        cout << "Queue is empty!\n";
        return -1;
    }
    else
    {
        return a[front];
    }
}
Graph::Graph()
{
    for (int v1 = 0; v1 < size; v1++)
    {
        for (int v2 = 0; v2 < size; v2++)
        {
            g[v1][v2] = false;
        }
    }
    for (int v1 = 0; v1 < size; v1++)
    {
        visit[v1] = false;
    }
}

void Graph::create()
{
    char ch;
    int flag = true;
    n = 0;
    do
    {
        cout << "Enter the Edge of graph u want to link: \n";
        cout << "Type -1 -1 for termination\n";
        cin >> v1 >> v2;
        if (v1 == -1)
        {
            break;
        }
        if (v1 >= size || v2 >= size)
        {
            cout << "Invalid Vertex value!\n";
        }
        else
        {
            g[v1][v2] = true;
            if (flag)
            {
                g[v2][v1] = true;
            }
        }
        n++;
    } while (1);
}

void Graph::BFS(int v1)
{
    Queuee q;
    visit[v1] = true;
    q.push(v1);
    while (!q.isEmpty())
    {
        v1 = q.pop();
        cout << v1 << " ";
        for (int v2 = 0; v2 < n; v2++)
        {
            if (g[v1][v2] == true && visit[v2] == false)
            {
                q.push(v2);
                visit[v2] = true;
            }
        }
    }
}

void Graph::recursiveDFS(int v1)
{
    int v2;
    cout << " " << v1;
    visit[v1] = true;
    for (int v2 = 0; v2 < n; v2++)
    {
        if (g[v1][v2] == true && visit[v2] == false)
        {
            recursiveDFS(v2);
        }
    }
}

// void Graph::iterativeDFS(int v1)
// {
//     Queuee q;
//     int v2;
//     q.push(v1);
//     while (!q.isEmpty())
//     {
//         v1 = q.pop();
//         if (visit[v1] == false)
//         {
//             cout << v1 << " ";
//             visit[v1] = true;
//         }
//         for (v2 = 0; v2 < n; v2++)
//         {
//             if (g[v1][v2] == true && visit[v2] == false)
//             {
//                 q.push(v2);
//             }
//         }
//     }
// }

void Graph::display()
{
    cout << "\nThe Graph Representation in Adjancency Matrix is: \n";
    for (int v1 = 0; v1 < n; v1++)
    {
        for (int v2 = 0; v2 < n; v2++)
        {

            cout << "     "
                 << " " << g[v1][v2];
        }
        cout << endl;
    }
}

int main()
{
    Graph g;
    int ch, v1;
    char ans;
    do
    {
        cout << "\n==================================================================================\n\n";
        cout << "\t\t\t\t Graph Array Representation\n";
        cout << "\n==================================================================================\n";

        cout << "\n1. Insert Vertices\n";
        cout << "2. BFS Traversal\n";
        cout << "3. DFS Recursive Traversal\n";
        cout << "4. DFS Iterative Traversal\n";
        cout << " Enter your Choice: \n";
        cin >> ch;
        switch (ch)
        {
        case 1:
            g.create();
            break;
        case 2:
            v1;
            cout << "Enter vertex from where u want to traverse: \n";
            cin >> v1;
            cout << " ***********  BFS Traversal ***********\n";
            g.BFS(v1);
            cout << '\n';
            g.display();
            break;
        case 3:
            v1;
            cout << "Enter vertex from where u want to traverse: \n";
            cin >> v1;
            cout << " ***********  Recursive DFS Traversal ***********\n";
            g.recursiveDFS(v1);
            cout << '\n';
            g.display();
            break;

        case 4:
            v1;
            cout << "Enter vertex from where u want to traverse: \n";
            cin >> v1;
            cout << " ***********  Iterative DFS Traversal ***********\n";
            // g.iterativeDFS(v1);
            break;

        default:

            break;
        }

        cout << "Do u want to continue?? (y/n) \n";
        cin >> ans;

    } while (ans == 'Y' || ans == 'y');
    return 0;
}
