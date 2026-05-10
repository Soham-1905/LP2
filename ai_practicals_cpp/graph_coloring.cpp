#include <iostream>

using namespace std;

int graph[10][10];
int color[10];
int n;

bool isSafe(int node, int c)
{
    for(int i=0; i<n; i++)
    {
        if(graph[node][i] && color[i] == c)
            return false;
    }

    return true;
}

bool solve(int node, int m)
{
    if(node == n)
        return true;

    for(int c=1; c<=m; c++)
    {
        if(isSafe(node, c))
        {
            color[node] = c;

            if(solve(node+1, m))
                return true;

            color[node] = 0;
        }
    }

    return false;
}

int main()
{
    int m;

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter adjacency matrix:\n";

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin >> graph[i][j];
        }
    }

    cout << "Enter number of colors: ";
    cin >> m;

    if(solve(0, m))
    {
        for(int i=0; i<n; i++)
        {
            cout << "Vertex " << i
                 << " -> Color " << color[i] << endl;
        }
    }
    else
    {
        cout << "No Solution";
    }

    return 0;
}
