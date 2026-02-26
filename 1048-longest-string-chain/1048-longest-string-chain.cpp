class Solution {
public:
    // Check if 'shorter' is predecessor of 'longer'
    bool check(string &shorter, string &longer) 
    {
        int i = 0, j = 0;

        // Try to match all characters of shorter inside longer
        while (i < shorter.length() && j < longer.length()) {
            if (shorter[i] == longer[j]) {
                i++;
            }
            j++;
        }

        // If we matched all characters of shorter
        return i == shorter.length();
    }

    int longestStrChain(vector<string>& words) {
        int n = words.size();

        // Sort words by increasing length
        sort(words.begin(), words.end(),
             [](string &a, string &b) {
                 return a.length() < b.length();
             });

        vector<int> dp(n, 1);   // dp[i] = longest chain ending at words[i]
        int maxLen = 1;

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                // Only check if length differs by exactly 1
                if (words[j].length() + 1 == words[i].length() &&
                    check(words[j], words[i])) {

                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            maxLen = max(maxLen, dp[i]);
        }

        return maxLen;
    }
};