#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void DFS(int v, vector<vector<int>>& adjMatrix, vector<bool>& visited) {
    visited[v] = true;
    cout << v << " ";

    for (int i = 0; i < adjMatrix[v].size(); i++) {
        if (adjMatrix[v][i] == 1 && !visited[i]) {
            DFS(i, adjMatrix, visited);
        }
    }
}

void BFS(int start, vector<vector<int>>& adjMatrix, vector<bool>& visited) {
  
    queue<int> queue;
    queue.push(start);
    visited[start] = true;
    while (!queue.empty()) {
        int v = queue.front();
        queue.pop();
        cout << v << " ";

        for (int i = 0; i < adjMatrix[v].size(); i++) {
            if (adjMatrix[v][i] == 1 && !visited[i]) {
                queue.push(i);
                visited[i] = true;
                
            }
        }
    }
}

int countConnectedComponents(vector<vector<int>>& adjMatrix) {
    int n= adjMatrix.size();
    vector<bool> visited(n, false);
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            DFS(i, adjMatrix, visited);
            count++;
        }
    }
    return count;
}

int main() {
    int n , e;
    cin >> n >> e;

    vector<vector<int>> adjMatrix(n, vector<int>(n, 0));
    vector<bool> visited(n, false);

    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1; 
    }

   
    cout << "DFS traversal starting from vertex 0:\n";
    DFS(0, adjMatrix, visited);
    cout << "\n";

   
    cout << "BFS traversal starting from vertex 0:\n";
    BFS(0, adjMatrix,visited);
    cout << "\n";

    int components = countConnectedComponents(adjMatrix);
    cout << "Number of connected components: " << components << endl;

    return 0;
}
