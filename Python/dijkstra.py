import heapq

def dijkstra(graph, start):
    # Create a dictionary to store the shortest path to each node
    shortest_paths = {node: float('inf') for node in graph}
    shortest_paths[start] = 0

    # Priority queue to explore the next most promising node
    priority_queue = [(0, start)]  # (cost, node)

    while priority_queue:
        current_distance, current_node = heapq.heappop(priority_queue)

        # Skip processing if a shorter path to the current node has already been found
        if current_distance > shortest_paths[current_node]:
            continue

        # Explore all neighbors of the current node
        for neighbor, weight in graph[current_node].items():
            distance = current_distance + weight

            # If a shorter path to the neighbor is found, update it
            if distance < shortest_paths[neighbor]:
                shortest_paths[neighbor] = distance
                heapq.heappush(priority_queue, (distance, neighbor))

    return shortest_paths

# Test the algorithm
graph = {
    'A': {'B': 1, 'C': 4},
    'B': {'A': 1, 'C': 2, 'D': 5},
    'C': {'A': 4, 'B': 2, 'D': 1},
    'D': {'B': 5, 'C': 1}
}

start_node = 'A'
shortest_paths = dijkstra(graph, start_node)

print(f"Shortest paths from node {start_node}:")
for node, distance in shortest_paths.items():
    print(f"To {node}: {distance}")
