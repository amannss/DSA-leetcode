
class Solution {
public:
    typedef pair<int, pair<int, int>> p;

    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        priority_queue<p, vector<p>, greater<p>> pq;

        unordered_map<int, vector<pair<int, int>>> mp;

        for (auto it : edges) {
            int u = it[0], v = it[1], w = it[2];
            mp[u].push_back({w, v});
        }

        vector<vector<int>> result(n, vector<int>(k + 1, INT_MAX));

        result[0][1] = 0;
        pq.push({0, {0, 1}});

        while (!pq.empty()) {
            p tops = pq.top();
            pq.pop();

            int u = tops.second.first;
            int w = tops.first;
            int cnt = tops.second.second;

            if (w != result[u][cnt]) continue;

            for (auto it : mp[u]) {
                int v = it.second;
                int d = it.first;

                int newcnt;

                if (labels[u] == labels[v])
                    newcnt = cnt + 1;
                else
                    newcnt = 1;

                if (newcnt <= k && w + d < result[v][newcnt]) {
                    result[v][newcnt] = w + d;
                    pq.push({w + d, {v, newcnt}});
                }
            }
        }

        int ans = INT_MAX;

        for (int i = 1; i <= k; i++) {
            ans = min(ans, result[n - 1][i]);
        }

        return ans == INT_MAX ? -1 : ans;
    }
};
