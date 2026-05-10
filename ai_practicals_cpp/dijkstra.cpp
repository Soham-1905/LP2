#include <iostream>

using namespace std;

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

    int visited[10] = {0};
    int distance[10];

    for(int i=0; i<n; i++)
    {
        distance[i] = 9999;
    }

    int start;

    cout << "Enter starting vertex: ";
    cin >> start;

    distance[start] = 0;

    for(int count=0; count<n-1; count++)
    {
        int min = 9999;
        int u;

        for(int i=0; i<n; i++)
        {
            if(!visited[i] && distance[i] < min)
            {
                min = distance[i];
                u = i;
            }
        }

        visited[u] = 1;

        for(int v=0; v<n; v++)
        {
            if(graph[u][v] &&
               !visited[v] &&
               distance[u] + graph[u][v] < distance[v])
            {
                distance[v] = distance[u] + graph[u][v];
            }
        }
    }

    cout << "\nShortest Distances:\n";

    for(int i=0; i<n; i++)
    {
        cout << start << " -> "
             << i << " = "
             << distance[i] << endl;
    }

    return 0;
}
