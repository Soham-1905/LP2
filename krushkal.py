def find(parent, i):
    if parent[i] != i:
        parent[i] = find(parent, parent[i])
    return parent[i]


def union(parent, rank, x, y):
    root_x = find(parent, x)
    root_y = find(parent, y)

    if rank[root_x] < rank[root_y]:
        parent[root_x] = root_y
    elif rank[root_x] > rank[root_y]:
        parent[root_y] = root_x
    else:
        parent[root_y] = root_x
        rank[root_x] += 1


def kruskal(vertices, edges):
    edges.sort(key=lambda x: x[2])

    parent = {v: v for v in vertices}
    rank = {v: 0 for v in vertices}

    mst = []
    total_cost = 0

    for u, v, w in edges:
        if find(parent, u) != find(parent, v):
            union(parent, rank, u, v)
            mst.append((u, v, w))
            total_cost += w

    print("\nEdges in Minimum Spanning Tree:")
    for u, v, w in mst:
        print(f"{u} -- {v} == {w}")

    print("Total Cost of MST:", total_cost)


# Input Section
n = int(input("Enter number of vertices: "))
vertices = []

for i in range(n):
    v = input(f"Enter vertex {i+1}: ")
    vertices.append(v)

e = int(input("Enter number of edges: "))
edges = []

for i in range(e):
    print(f"\nEdge {i+1}:")
    u = input("Enter first vertex: ")
    v = input("Enter second vertex: ")
    w = int(input("Enter weight: "))
    edges.append((u, v, w))

kruskal(vertices, edges)