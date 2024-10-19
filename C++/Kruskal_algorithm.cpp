#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, w;
};

int findParent(int node, vector<int>& parent) {
    if (parent[node] == node)
        return node;
    return parent[node] = findParent(parent[node], parent);
}

void unionSets(int u, int v, vector<int>& parent, vector<int>& rank) {
    int rootU = findParent(u, parent);
    int rootV = findParent(v, parent);
    if (rank[rootU] < rank[rootV]) {
        parent[rootU] = rootV;
    } else if (rank[rootU] > rank[rootV]) {
        parent[rootV] = rootU;
    } else {
        parent[rootV] = rootU;
        rank[rootU]++;
    }
}

vector<pair<pair<int, int>, int>> calculateKruskalMST(int n, int m, vector<Edge>& edges) {
    vector<int> parent(n+1), rank(n+1, 0);
    vector<pair<pair<int, int>, int>> result;

    for (int i = 1; i <= n; i++)
        parent[i] = i;

    sort(edges.begin(), edges.end(), [](Edge& a, Edge& b) {
        return a.w < b.w;
    });

    for (Edge& edge : edges) {
        int rootU = findParent(edge.u, parent);
        int rootV = findParent(edge.v, parent);

        if (rootU != rootV) {
            result.push_back({{edge.u, edge.v}, edge.w});
            unionSets(rootU, rootV, parent, rank);
        }
    }

    return result;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<Edge> edges(m);

    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    vector<pair<pair<int, int>, int>> answer = calculateKruskalMST(n, m, edges);

    for (auto& x : answer) {
        cout << x.first.first << "-" << x.first.second << " : " << x.second << endl;
    }

    return 0;
}
