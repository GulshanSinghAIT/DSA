#include <bits/stdc++.h>
using namespace std;

int mstWeight(vector<vector<int>> &edges, int n)
{
    vector<pair<int, int>> adj[n];
    vector<int> visited(n, 0);
    int ans = 0;

    for (auto i : edges)
    {
        adj[i[0]].push_back({i[1], i[2]});
        adj[i[1]].push_back({i[0], i[2]});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});

    while (!pq.empty())
    {
        auto top = pq.top();
        pq.pop();
        int weight = top.first;
        int vertex = top.second;

        if(visited[vertex]==1){
            continue;
        }
        visited[vertex]=1;
        ans+=weight;

        for(auto i: adj[vertex]){
            if(!visited[i.first]){
                pq.push({i.second,i.first});
            }
        }
    }
}

int main()
{
    int n, e;
    cout << "enter the no of vertex" << endl;
    cin >> n;
    cout << "Enter the no of edges" << endl;
    cin >> e;
    vector<vector<int>> edges;
    cout << "Enter the edges in the format (u v w) " << endl;

    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    int mst_wt = mstWeight(edges, n);
    cout << "Min weight" << mst_wt << endl;
}