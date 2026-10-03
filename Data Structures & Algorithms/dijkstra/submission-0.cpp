class Solution {
public:
    unordered_map<int, int> shortestPath(int n, vector<vector<int>>& edges, int src) {
        const int INF = 1e5;
        unordered_map<int, int> s_path(n);
        vector<int> dist(n, INF);
        vector<bool> visited(n, false);

        dist[src] = 0;

        // Edges reorganization
        vector<vector<pair<int, int>>> adj(n);
        for (auto& e : edges){
            adj[e[0]].push_back({e[1], e[2]});
        }

        for (int i = 0; i < n; ++i) // as many as nodes
        {
            int u = -1;
            for (int j = 0; j < n; ++j){ // Iterate to each node
                if (!visited[j] && (u == -1 || dist[j] < dist[u])){
                    u = j;
                }
            }

            if (u == -1 || dist[u] == INF) // Validation of u
                break;
            visited[u] = true;

            for (auto& [v, w] : adj[u]){ // Search for min and update min value dist.
                if(dist[u] + w < dist[v]){
                    dist[v] = dist[u] + w;
                }
            }
            
        }
        for (int i = 0; i < n; ++i){ // return structure construction
            s_path[i] = (dist[i] == INF) ? -1 : dist[i];
        }
        return s_path;
    }
};
