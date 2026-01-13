class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double low = 1e18, high = -1e18;
        double totalArea = 0.0;

        // Find bounds and total area
        for (auto &s : squares) {
            double y = s[1];
            double l = s[2];
            low = min(low, y);
            high = max(high, y + l);
            totalArea += l * l;
        }

        double target = totalArea / 2.0;

        // Binary search
        for (int it = 0; it < 60; it++) {
            double mid = (low + high) / 2.0;
            double areaBelow = 0.0;

            for (auto &s : squares) {
                double y = s[1];
                double l = s[2];

                if (mid <= y) continue;
                else if (mid >= y + l)
                    areaBelow += l * l;
                else
                    areaBelow += l * (mid - y);
            }

            if (areaBelow < target)
                low = mid;
            else
                high = mid;
        }

        return (low + high) / 2.0;
    }
};

