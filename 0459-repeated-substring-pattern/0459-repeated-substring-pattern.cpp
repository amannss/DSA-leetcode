class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.length() ;
        string p = s ;
        for(int i =0 ; i < n - 1 ;i++)
        {
            rotate(p.begin() , p.begin() + 1 , p.end() ) ;
            if(p == s) return true ;
        }
        return false ;
    }
};