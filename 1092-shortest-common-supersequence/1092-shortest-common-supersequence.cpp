class Solution {
public:
    typedef vector<vector<int>> V;
    void backtrack(V dp, string &common, int i, int j, string& s1, string& s2) {
        if (i <= 0 || j <= 0)
            return;
        if (s1[i - 1] == s2[j - 1]) {
            common += s1[i - 1];
            backtrack(dp, common, i - 1, j - 1, s1, s2);
        } else {
            if (dp[i - 1][j] == dp[i][j]) {
                backtrack(dp, common, i - 1, j, s1, s2);
            }
            else if (dp[i][j - 1] == dp[i][j]) {
                backtrack(dp, common, i, j - 1, s1, s2);
            }
        }
    }
    string shortestCommonSupersequence(string s1, string s2) {
        int m = s1.length();
        int n = s2.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        string lcs = "";
        backtrack(dp, lcs, m, n, s1, s2);
        reverse(lcs.begin(), lcs.end());
        
        string scs = "" ;
        int i=0;int j=0 ;
        for(char c : lcs)
        {
            while(s1[i] != c) scs+=s1[i++] ;
            while(s2[j] != c) scs+=s2[j++] ;
            scs += c; 
            i++ ; j++ ;
        }
        scs += s1.substr(i) ;
        scs += s2.substr(j) ;
        return  scs ;
    }
};