#include <iostream>
#include <vector>

using namespace std;

vector<int> graph[10];
bool visited[10];

void DFS(int node)
{
    visited[node] = true;

    cout << node << " ";

    for(int neighbour : graph[node])
    {
        if(!visited[neighbour])
        {
            DFS(neighbour);
        }
    }
}

int main()
{
    int edges;
    cout << "Enter number of edges: ";
    cin >> edges;

    cout << "Enter edges:\n";

    for(int i=0; i<edges; i++)
    {
        int u,v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int start;
    cout << "Enter starting node: ";
    cin >> start;

    cout << "DFS Traversal: ";
    DFS(start);

    return 0;
}
