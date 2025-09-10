#include <bits/stdc++.h>
using namespace std;
class Graph {
public:
    int V;
    vector<vector<int>> adj;
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool isCyclic() {
        vector<bool> visited(V, false);
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (dfs(i, visited, -1))
                    return true;
            }
        }
        return false;
    }
private:
    bool dfs(int node, vector<bool>& visited, int parent) {
        visited[node] = true;

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                if (dfs(neighbor, visited, node))
                    return true;
            }
            else if (neighbor != parent) {
                return true;
            }
        }
        return false;
    }
};
int main() {
    int V = 5;
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 0}};
    Graph g(V);
    for (auto& e : edges) {
        g.addEdge(e[0], e[1]);
    }
    cout << (g.isCyclic() ? "true" : "false") << endl;
    return 0;
}
