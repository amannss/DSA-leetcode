class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        // dp[i][j] = max dot product using non-empty subsequences
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1e9));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                int prod = nums1[i - 1] * nums2[j - 1];

                dp[i][j] = max({
                    prod,                    // start new subsequence
                    dp[i - 1][j - 1] + prod, // extend subsequence
                    dp[i - 1][j],            // skip nums1[i-1]
                    dp[i][j - 1]             // skip nums2[j-1]
                });
            }
        }

        return dp[n][m];
    }
};
