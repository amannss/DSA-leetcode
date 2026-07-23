class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        int i = 0, j = 0;
        int maxfreq = 0;
        int ans = 0;

        unordered_map<char, int> mp;

        while (j < n)
        {
            mp[s[j]]++;
            maxfreq = max(maxfreq, mp[s[j]]);
            j++;

            int temp = (j - i) - maxfreq;

            while (temp > k && i < j)
            {
                mp[s[i]]--;
                i++;
                temp = (j - i) - maxfreq;
            }

            ans = max(ans, j - i);
        }

        return ans;
    }
};