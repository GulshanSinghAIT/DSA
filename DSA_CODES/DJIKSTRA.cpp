#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;

void insert(int e, vector<vector<int>>& adj) {
    for (int i = 0; i < e; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u][v] = wt;
        adj[v][u] = wt;
    }
}

void display(int V, vector<vector<int>>& adj) {
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
}

pair<vector<int>, vector<int>> djikstra(vector<vector<int>>& adj, int src, int dest, int v) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});
    vector<int> dist(v, INT_MAX);
    vector<int> par(v);
    for (int i = 0; i < v; i++) {
        par[i] = i;
    }
    dist[src] = 0;
    while (!pq.empty()) {
        int node = pq.top().second;
        int dis = pq.top().first;
        pq.pop();
        for (int i = 0; i < v; i++) {
            if (adj[node][i] != 0) {
                int adjn = i;
                int edw = adj[node][i];
                if (edw + dis < dist[adjn]) {
                    dist[adjn] = dis + edw;
                    pq.push({dist[adjn], adjn});
                    par[adjn] = node;
                }
            }
        }
    }
    if (dist[dest] == INT_MAX) {
        return {{}, {}};
    }
    vector<int> ans;
    int node = dest;
    while (par[node] != node) {
        ans.push_back(node);
        node = par[node];
    }
    ans.push_back(src);
    reverse(ans.begin(), ans.end());
    return {dist, ans};
}

int main() {
    int V, E;
    cout << "Enter number of offices and lines: ";
    cin >> V >> E;
    vector<vector<int>> adj(V, vector<int>(V, 0));
    insert(E, adj);
    cout << "Enter src and dest: ";
    int s, d;
    cin >> s >> d;
    pair<vector<int>, vector<int>> p = djikstra(adj, s, d, V);
    vector<int> dist = p.first;
    vector<int> path = p.second;
    cout << "Distances: ";
    for (int i = 0; i < V; i++) {
        if (dist[i] != INT_MAX) {
            cout << dist[i] << " ";
        }
    }
    cout << endl << "Path is: ";
    for (int i = 0; i < path.size(); i++) {
        cout << path[i] << " ";
    }
    return 0;
}

