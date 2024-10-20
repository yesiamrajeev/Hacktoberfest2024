#include <bits/stdc++.h>
using namespace std;

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    unordered_map<int, list<int>> adj;
    for(int i=0; i<edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u]. push_back(v);
    }

    vector<int> indegree(v, 0);
    queue<int> q;
    vector<int> ans;

    for(auto i: adj){
        for(auto j: i.second)
            indegree[j]++;
    }

    for(int i=0; i<v; i++){
        if(indegree[i] == 0)
            q.push(i);
    }

    while(!q.empty()){
        int front = q.front();
        q.pop();

        ans.push_back(front);

        for(auto neighbour : adj[front]){
            indegree[neighbour]--;
            if(indegree[neighbour] == 0)
                q.push(neighbour);
        }
    }
    return ans;
}

int main()
{
	vector<vector<int>> edges;
	int n, m;

	int tc;
	cin >> tc;
	while (tc--)
	{
		cout << "Enter number of nodes and edges: ";
		cin >> n >> m;

		for (int i = 0; i < m; i++)
		{
			int u, v;
			cin >> u >> v;
			edges.push_back({u, v});
		}

		vector<int> topSort = topologicalSort(edges, n, m);

		cout << "Topological Sort : ";
		for (int x : topSort)
		{
			cout << x << " ";
		}
		cout << endl;
	}
	return 0;
}
