#include <bits/stdc++.h> 
using namespace std;
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector< vector<int> > &edges)
{
    unordered_map< int, list<pair<int,int>> > adj;
    for(int i=0; i<m; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];

        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    vector<int> key(n+1, INT_MAX);
    vector<bool> mst(n+1, false);
    vector<int> parent(n+1, -1);

    key[1] = 0;
    parent[1] = -1;

    for(int i=1; i<n; i++){
        int mini = INT_MAX;
        int u;

        for(int v=1; v<=n; v++){
            if(mst[v] == false && key[v] < mini){
                u = v;
                mini = key[v];
            }
        }

        mst[u] = true;

        for(auto it: adj[u]){
            int v = it.first;
            int w = it.second;
            if(mst[v] == false && key[v] > w){
                parent[v] = u;
                key[v] = w;
            }
        }
    }

    vector<pair<pair<int, int>, int>> result;
    for(int i=2; i<=n; i++){
        int u = parent[i];
        int v = i;
        int w = key[i];
        result.push_back({{u,v},w});
    }
    return result;
}

int main(){
	vector<vector<int>> edges;
    int n, m, src;

    cin >> n;
    
    cin >> m;

    for(int i=0; i<m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u,v,w});
    }

    vector< pair<pair<int,int>, int> >  answer = calculatePrimsMST(n, m, edges);

    for(pair<pair<int,int>, int> x : answer) {
        pair<int,int> a = x.first;
        int b = x.second;

        /*
            a.first -> u
            a.second -> v
            b -> weight
        */
        cout << a.first << "-" << a.second << " : " << b << endl;
    }

    return 0;
}
