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


def dfs(graph, start, goal):
    visited = []
    stack = []

    stack.append(start)

    print("\nDFS Traversal is:")

    while stack:
        node = stack.pop()

        if node not in visited:
            print(node, end=" ")
            visited.append(node)

            if node == goal:
                print("\nGoal Node Found!")
                return

            for n in reversed(graph[node]):
                if n not in visited:
                    stack.append(n)


# -------- USER INPUT PART --------
graph = {}

n = int(input("Enter number of nodes: "))

for i in range(n):
    node = input("Enter node {}: ".format(i+1))
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
dfs(graph, start_node, goal_node)