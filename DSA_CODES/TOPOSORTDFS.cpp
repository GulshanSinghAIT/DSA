#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void dfs(int node, vector<vector<int>>& graph, vector<bool>& visited, stack<int>& st) {
    visited[node] = true;
    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, graph, visited, st);
        }
    }
    st.push(node);
}


vector<int> topologicalSort(vector<vector<int>>& graph, int n) {
    vector<int> result;
    vector<bool> visited(n, false);
    stack<int> st;

    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            dfs(i, graph, visited, st);
        }
    }


    while (!st.empty()) {
        result.push_back(st.top());
        st.pop();
    }

    return result;
}

int main() {
    int n, e;
    cout << "Enter the number of nodes and edges: ";
    cin >> n >> e;

    vector<vector<int>> graph(n);
    cout << "Enter the edges (format: u v):" << endl;
    for (int i = 0; i <n; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }

    vector<int> sortedNodes = topologicalSort(graph,n);

    cout << "Topological order: ";
    for (int node : sortedNodes) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
