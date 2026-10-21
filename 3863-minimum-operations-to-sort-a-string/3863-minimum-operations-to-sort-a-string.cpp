class Solution {
public:
    int minOperations(string s) {
        int n = s.length() ;
        string s2 = s ;
        sort(s2.begin(), s2.end()) ;
        if(s == s2 ) return 0 ;

        if(n==2) return -1 ;

        char mx = *max_element(s.begin() , s.end() ) ;
        char mn = *min_element(s.begin() , s.end() ) ;


        char minInMid = *min_element(s.begin() +1 , s.end() -1 ) ;
        char maxInMid = *max_element(s.begin() + 1 , s.end() - 1 ) ;


        if(s[0] == mn || s[n-1] == mx  ) return 1 ;
        else if(s[0] > maxInMid && minInMid > s[n-1] ) return 3;

        return 2 ;
    }
};