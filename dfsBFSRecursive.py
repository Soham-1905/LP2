def bfs(graph, start_node, goal_node):
    visited = []
    queue = []

    visited.append(start_node)
    queue.append(start_node)

    print("BFS Traversal is:")

    while queue:
        m = queue.pop(0)
        print(m, end=" ")

        if m == goal_node:
            print("\nNode Found!")
            return

        for n in graph[m]:
            if n not in visited:
                visited.append(n)
                queue.append(n)


# 🔷 RECURSIVE DFS
def dfs_recursive(graph, node, goal, visited):
    if node not in visited:
        print(node, end=" ")
        visited.append(node)

        if node == goal:
            print("\nGoal Node Found!")
            return True   # important to stop recursion

        for n in graph[node]:
            if dfs_recursive(graph, n, goal, visited):
                return True


# -------- USER INPUT --------
graph = {}

n = int(input("Enter number of nodes: "))

for i in range(n):
    node = input(f"Enter node {i+1}: ")
    edges = int(input(f"Enter number of adjacent nodes for {node}: "))

    neighbours = []
    for j in range(edges):
        neighbour = input(f"Enter neighbour {j+1} of {node}: ")
        neighbours.append(neighbour)

    graph[node] = neighbours

start_node = input("Enter start node: ")
goal_node = input("Enter goal node: ")

# -------- FUNCTION CALLS --------
bfs(graph, start_node, goal_node)

print("\nDFS Traversal is:")
dfs_recursive(graph, start_node, goal_node, [])