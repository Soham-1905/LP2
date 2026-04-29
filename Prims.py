import heapq

def prim(graph, start):
    visited = set()
    min_heap = [(0, start)]
    total_cost = 0

    while min_heap:
        weight, node = heapq.heappop(min_heap)

        if node not in visited:
            visited.add(node)
            total_cost += weight
            print("Visited:", node, "Weight:", weight)

            for neighbor, w in graph[node]:
                if neighbor not in visited:
                    heapq.heappush(min_heap, (w, neighbor))

    print("Total Cost of MST:", total_cost)


# 🔹 Input Section
n = int(input("Enter number of vertices: "))
graph = {}

for i in range(n):
    node = input(f"Enter vertex {i+1}: ")
    edges = int(input(f"Enter number of neighbors for {node}: "))

    neighbors = []
    for j in range(edges):
        neighbor = input("Enter neighbor vertex: ")
        weight = int(input("Enter weight: "))
        neighbors.append((neighbor, weight))

    graph[node] = neighbors


start = input("Enter starting node: ")

# 🔹 Run Prim's Algorithm
prim(graph, start)