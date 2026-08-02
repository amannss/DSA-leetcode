class Solution {
public:
    int countValidPrefixes(string s) {
        int ans = 0 ;
        int cnt0 = 0 , cnt1 = 0 ;
        for(char c : s)
        {
            if(c == '0') cnt0++ ;
            else cnt1++ ;
            if(abs(cnt1 - cnt0) <= 1 ) ans++ ;
        }
        return ans ;
    }
};