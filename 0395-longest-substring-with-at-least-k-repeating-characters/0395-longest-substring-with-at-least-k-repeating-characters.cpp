class Solution {
public:
    int longestSubstring(string s, int k) {

        int n = s.length();
        int ans = 0;

        // Try every possible number of unique characters
        for (int targetUnique = 1; targetUnique <= 26; targetUnique++)
        {
            vector<int> freq(26, 0);

            int i = 0, j = 0;
            int unique = 0;
            int countAtLeastK = 0;

            while (j < n)
            {
                if (freq[s[j] - 'a'] == 0)
                    unique++;

                freq[s[j] - 'a']++;

                if (freq[s[j] - 'a'] == k)
                    countAtLeastK++;

                j++;

                while (unique > targetUnique)
                {
                    if (freq[s[i] - 'a'] == k)
                        countAtLeastK--;

                    freq[s[i] - 'a']--;

                    if (freq[s[i] - 'a'] == 0)
                        unique--;

                    i++;
                }

                if (unique == targetUnique &&
                    unique == countAtLeastK)
                {
                    ans = max(ans, j - i);
                }
            }
        }

        return ans;
    }
};