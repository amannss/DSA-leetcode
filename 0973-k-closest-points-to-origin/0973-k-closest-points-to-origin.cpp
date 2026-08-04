class Solution {
public:
    typedef pair<int, pair<int, int>> p;

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        priority_queue<p> pq;

        for (auto &it : points) {
            int x = it[0];
            int y = it[1];

            int dist = x * x + y * y;

            pq.push({dist, {x, y}});

            if (pq.size() > k)
                pq.pop();
        }

        vector<vector<int>> result;

        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();

            result.push_back({top.second.first, top.second.second});
        }

        return result;
    }
};