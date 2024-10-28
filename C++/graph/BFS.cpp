// Implementation of Breadth-First Search (BFS) in C++ for an undirected graph

#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
#include <vector>

class Graph {
private:
    // Adjacency list to store the graph, where each vertex points to a list of connected vertices
    std::unordered_map<int, std::list<int>> adjList;

public:
    /**
     * @brief Adds an edge between two vertices in the graph.
     * @param v1 The first vertex.
     * @param v2 The second vertex.
     * Since this is an undirected graph, both v1 -> v2 and v2 -> v1 edges are added.
     */
    void addEdge(int v1, int v2) {
        adjList[v1].push_back(v2);
        adjList[v2].push_back(v1);  // Since the graph is undirected
    }

    /**
     * @brief Performs Breadth-First Search (BFS) traversal from a given source vertex.
     * @param start The starting vertex for BFS traversal.
     */
    void BFS(int start) {
        // Check if the start vertex exists in the graph
        if (adjList.find(start) == adjList.end()) {
            std::cerr << "Error: Starting vertex " << start << " not found in the graph." << std::endl;
            return;
        }

        // Vector to track visited vertices, initialized to `false`
        std::vector<bool> visited(adjList.size(), false);
        
        // Queue to manage the BFS traversal order
        std::queue<int> q;

        // Mark the start vertex as visited and enqueue it
        visited[start] = true;
        q.push(start);

        // Continue BFS until the queue is empty
        while (!q.empty()) {
            // Dequeue a vertex from the front of the queue
            int v = q.front();
            q.pop();
            std::cout << v << " "; // Process the vertex

            // Iterate over all adjacent vertices of the dequeued vertex
            for (int neighbor : adjList[v]) {
                if (!visited[neighbor]) { 
                    // If the neighbor has not been visited, mark it as visited and enqueue it
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        std::cout << std::endl; // Print newline after BFS traversal
    }
};

int main() {
    Graph g;

    // Adding edges to the graph
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    // Perform BFS starting from vertex 0
    std::cout << "BFS starting from vertex 0:" << std::endl;
    g.BFS(0);

    return 0;
}
