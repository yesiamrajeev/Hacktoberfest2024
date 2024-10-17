#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// Dijkstra's algorithm function to find the shortest path
void dijkstra(vector<vector<pair<int, int>>> &graph, int src) {
    int V = graph.size();
    vector<int> dist(V, INT_MAX); // Distance from source to each node
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (auto &neighbor : graph[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    // Output the shortest distances
    for (int i = 0; i < V; ++i)
        cout << "Distance from " << src << " to " << i << " is " << dist[i] << endl;
}

int main() {
    int V = 5; // Number of vertices
    vector<vector<pair<int, int>>> graph(V);

    // Add edges (u, v, w)
    graph[0].push_back({1, 9});
    graph[0].push_back({2, 6});
    graph[0].push_back({3, 5});
    graph[0].push_back({4, 3});
    graph[2].push_back({1, 2});
    graph[2].push_back({3, 4});

    dijkstra(graph, 0);
    return 0;
}
