#include <iostream>
#include <vector>
#include<queue>
#include<algorithm>
using namespace std;


vector<int>shortestpath(int n,vector<vector<int>>&edges){
        vector<pair<int,int>>adj[n+1];
        for(auto& it:edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>dist(n+1,1e9),parent(n+1);
        for(int i=1;i<=n;i++){
            parent[i]=i;
        }
        dist[0]=0;
        pq.push({0,0});
        while(!pq.empty()){
            auto it=pq.top();
            int node=it.second;
            int dis=it.first;
            pq.pop();

            for(auto it:adj[node]){
                int adjnode=it.first;
                int edW=it.second;
                if(dis+edW  <dist[adjnode]){
                    dist[adjnode]=dis+edW;
                    pq.push({dis+edW ,adjnode});
                    parent[adjnode]=node;

                }
            }
        }
        if(dist[n]==1e9){
            return {-1};
        }
        vector<int>path;
        int node=n;
        while(parent[node] != node){
            path.push_back(node);
            node=parent[node];
        }
        path.push_back(0);
        reverse(path.begin(),path.end());
        return path;
}

int main(){
    int n;
    int e;
    cin>>n>>e;
    
    vector<vector<int>> edges;
    for (int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    vector<int> result = shortestpath(n, edges);
    for (int node : result) {
        cout << node << " ";
    }
    cout << endl;
    return 0;

}