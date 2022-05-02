#include <iostream>
using namespace std;

class Graph
{
    int vertex;
    int edges;
    int **adj_matrix;
public:
    Graph(int v, int e)
    {
        vertex = v;
        edges = e;
        adj_matrix = new int *[v];
        for (int i = 0; i < v; i++)
        {
            adj_matrix[i] = new int[v];
        }
    }

    void accept_graph()
    {
        for (int i = 0; i < vertex; i++)
        {
            for (int j = 0; j < vertex; j++)
            {
                adj_matrix[i][j] = 0;
            }
        }
        for (int i = 0; i < edges; i++)
        {
            int s, d, w;
            cout << "\n";
            cout << "Enter source : ";
            cin >> s;
            cout << "Enter destination : ";
            cin >> d;
            cout << "Enter weight : ";
            cin >> w;
            adj_matrix[s][d] = adj_matrix[d][s] = w;
        }
    }

    void display()
    {
        for (int i = 0; i < vertex; i++)
        {
            cout << i << "--> | ";
            for (int j = 0; j < vertex; j++)
            {
                cout <<adj_matrix[i][j] << " ";
            }
            cout << "|\n";
        }
    }
};

int main()
{
    cout << "\n\nACCEPTING GRAPH WITH WEIGHT\n\n";
    int v, e;
    cout << "Enter no of vertices : ";
    cin >> v;
    cout << "Enter no of edges : ";
    cin >> e;
    Graph g(v, e);
    g.accept_graph();
    int var = 1;
    while(var == 1)
    {
        int ch;
        cout<<"\n\n---------------MENU-------------\n\n";
        cout<<"Enter your choice :\n1)Display Adjacency Matrix \n2) \n3)\n";
        cin>>ch;
        switch(ch)
        {
            case 1:
            {
                cout<<"\nAdjacency Matrix\n";
                g.display();
                break;
            }
            default:
            {
                cout<<"\nEnter correct choice!";
                break;
            }
        }
        cout<<"\nDo you want to continue (0/1) :";
        cin>>var;
    }
}
