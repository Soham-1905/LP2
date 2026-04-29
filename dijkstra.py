import heapq

def dijkstra(graph, start):
    dist = {node: float('inf') for node in graph}
    dist[start] = 0
    pq = [(0, start)]

    while pq:
        current_dist, node = heapq.heappop(pq)

        for neighbor, weight in graph[node]:
            distance = current_dist + weight

            if distance < dist[neighbor]:
                dist[neighbor] = distance
                heapq.heappush(pq, (distance, neighbor))

    return dist


n = int(input("Enter number of nodes: "))
graph = {}

for i in range(n):
    node = input(f"Enter node {i+1}: ")
    edges = int(input(f"Enter number of neighbors for {node}: "))

    neighbors = []
    for j in range(edges):
        neighbor = input("Enter neighbor node: ")
        weight = int(input("Enter weight: "))
        neighbors.append((neighbor, weight))

    graph[node] = neighbors


start = input("Enter start node: ")

result = dijkstra(graph, start)

print("\nShortest distances from", start)
for node in result:
    print(node, ":", result[node])