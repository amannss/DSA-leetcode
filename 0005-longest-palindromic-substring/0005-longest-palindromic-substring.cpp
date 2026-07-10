class Solution {
public:
    int t[1001][1001];

    bool check(const string &s, int i, int j) {
        if (i >= j)
            return true;

        if (t[i][j] != -1)
            return t[i][j];

        if (s[i] == s[j]) {
            return t[i][j] = check(s, i + 1, j - 1);
        }

        return t[i][j] = false;
    }

    string longestPalindrome(string s) {
        memset(t, -1, sizeof(t));

        int maxlen = 1;
        int sp = 0;
        int n = s.length();

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (check(s, i, j)) {
                    if (j - i + 1 > maxlen) {
                        maxlen = j - i + 1;
                        sp = i;
                    }
                }
            }
        }

        return s.substr(sp, maxlen);
    }
};