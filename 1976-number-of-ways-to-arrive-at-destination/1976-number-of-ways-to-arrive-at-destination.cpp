class Solution {
public:
    int countPaths(int V, vector<vector<int>>& edges) {
        
        typedef pair<long long, int> p;
        const int mod = 1e9 + 7;

        vector<long long> dist(V, LLONG_MAX);
        vector<int> path(V, 0);

        vector<vector<pair<int,int>>> adj(V);

        for(auto &it : edges) {
            int u = it[0], v = it[1], w = it[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        priority_queue<p, vector<p>, greater<p>> pq;

        dist[0] = 0;
        path[0] = 1;

        pq.push({0, 0});

        while(!pq.empty()) {
            auto it = pq.top(); pq.pop();
            long long w = it.first;
            int u = it.second;

            // 🔥 important line
            // if(w > dist[u]) continue;

            for(auto &nghbr : adj[u]) {
                int v = nghbr.first;
                int d = nghbr.second;

                if(w + d < dist[v]) {
                    dist[v] = w + d;
                    path[v] = path[u];
                    pq.push({dist[v], v});
                }
                else if(w + d == dist[v]) {
                    path[v] = (path[v] + path[u]) % mod;
                }
            }
        }

        return path[V-1] % mod;
    }
};