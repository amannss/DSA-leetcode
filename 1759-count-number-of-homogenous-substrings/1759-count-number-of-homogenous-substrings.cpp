class Solution {
public:
    int countHomogenous(string s) {
        int mod = 1e9 + 7 ;
        int len = 0 ;
        int n = s.length() ;
        int cnt = 0  ;
        for(int i =0;i<n;i++)
        {
            if(i!= 0 && s[i] == s[i-1])
            {
                len++ ;
            }
            else
            {
                len = 1 ;
            }
            cnt = (cnt + len ) % mod  ;
        }
        return cnt % mod  ;
    }
};