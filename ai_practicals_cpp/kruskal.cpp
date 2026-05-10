#include <iostream>

using namespace std;

int parent[10];

int find(int i)
{
    while(parent[i] != i)
    {
        i = parent[i];
    }

    return i;
}

void unionSet(int a, int b)
{
    int x = find(a);
    int y = find(b);

    parent[x] = y;
}

int main()
{
    int n;

    cout << "Enter number of vertices: ";
    cin >> n;

    int graph[10][10];

    cout << "Enter adjacency matrix:\n";

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin >> graph[i][j];
        }
    }

    for(int i=0; i<n; i++)
    {
        parent[i] = i;
    }

    cout << "\nEdges in MST:\n";

    int edges = 0;

    while(edges < n-1)
    {
        int min = 9999;
        int a = -1;
        int b = -1;

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(graph[i][j] < min && graph[i][j] != 0)
                {
                    min = graph[i][j];
                    a = i;
                    b = j;
                }
            }
        }

        int x = find(a);
        int y = find(b);

        if(x != y)
        {
            cout << a << " - " << b
                 << " : " << min << endl;

            unionSet(x, y);

            edges++;
        }

        graph[a][b] = graph[b][a] = 9999;
    }

    return 0;
}
