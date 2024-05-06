#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, e;
    cin >> n >> e;

    vector<vector<int>> adj(n);
    vector<int> indegree(n, 0);
    int u, v;

  
    for (int i = 0; i < e; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        indegree[v]++;
    }

    queue<int> q;
   
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> topOrder; 

    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        topOrder.push_back(curr);

     
        for (int neighbor : adj[curr]) {
            indegree[neighbor]--;
          
            if (indegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    if (topOrder.size() != n) {
        cout << "Cycle detected, no topological sort possible" << endl;
    } else {
        for (int elem : topOrder) {
            cout << elem << " ";
        }
        cout << endl;
    }

    return 0;
}
