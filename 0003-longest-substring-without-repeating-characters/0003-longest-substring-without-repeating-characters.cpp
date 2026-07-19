class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0 , r = 0 ;
        unordered_map< char , int > mp ;
        int n = s.length() ;
        int maxlen = 0 ;
        while(r < n) 
        {   
            if(mp.find(s[r]) != mp.end() && mp[s[r]] >= l)
            {
                l = mp[s[r]] +1 ;
            }
            maxlen = max(maxlen , r-l +1) ;
            mp[s[r]] = r ;
            r++ ;   
        }
        return maxlen ;
    }
};