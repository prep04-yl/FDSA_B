#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void DFS(int node, vector<int> adj[], bool visited[]) {
    visited[node] = true;
    cout << node << " ";

    for (int i = 0; i < adj[node].size(); i++) {
        int next = adj[node][i];
        if (!visited[next])
            DFS(next, adj, visited);
    }
}

void BFS(int start, vector<int> adj[], int n) {
    bool visited[n+1 ] = {};
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int i = 0; i < adj[node].size(); i++) {
            int next = adj[node][i];

            if (!visited[next]) {
                visited[next] = true;
                q.push(next);
            }
        }
    }
}

int main() {
    int n, e, u, v, start;

    cout << "Enter number of buildings and roads: ";
    cin >> n >> e;

    vector<int> adj[n+1];

    cout << "Enter roads (building1 building2):\n";
    for (int i = 0; i < e; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << "Enter starting building: ";
    cin >> start;

    bool visited[n+1] = {};

    cout << "DFS: ";
    DFS(start, adj, visited);

    cout << "\nBFS: ";
    BFS(start, adj, n);

    return 0;
}
