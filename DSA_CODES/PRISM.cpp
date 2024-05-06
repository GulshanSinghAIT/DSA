#include <iostream>
#include <vector>
#include <queue> 
#include <utility>
using namespace std;


int minimumSpanningTree(vector<vector<int>>& edges, int n) {
    vector<pair<int, int>> adj[n];
    vector<int> visited(n, 0);
    int ans = 0; 
    

    for(auto i : edges) {
        adj[i[0]].push_back({i[1], i[2]});
        adj[i[1]].push_back({i[0], i[2]});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0}); 

    while(!pq.empty()) {
        auto top = pq.top();
        pq.pop();
        int weight = top.first;                                                       
        int vertex = top.second;

        if(visited[vertex] == 1) {
            continue;
        }

        visited[vertex] = 1;
        ans += weight; 

       
        for(auto i : adj[vertex]) {
            if(!visited[i.first]) {
                pq.push({i.second, i.first});
            }
        }
    }
    return ans;
}

int main() {
    int n, e;
    cout << "Enter the number of vertices: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> e;

    vector<vector<int>> edges;

    cout << "Enter the edges in the format (u v w):" << endl;
    for (int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    int mst_weight = minimumSpanningTree(edges, n);
    cout << "The weight of the Minimum Spanning Tree is: " << mst_weight << endl;

    return 0;
}
