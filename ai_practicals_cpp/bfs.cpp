#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> graph[10];
bool visited[10];

void BFS(int start)
{
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while(!q.empty())
    {
        int node = q.front();
        q.pop();

        cout << node << " ";

        for(int neighbour : graph[node])
        {
            if(!visited[neighbour])
            {
                visited[neighbour] = true;
                q.push(neighbour);
            }
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

    cout << "BFS Traversal: ";
    BFS(start);

    return 0;
}
