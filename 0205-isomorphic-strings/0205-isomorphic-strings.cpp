class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char , char > m1 ;
        unordered_map<char , char > m2 ;
        for(int i=0;i<s.length() ;i++)
        {   
            char c1 = s[i] ; char c2 = t[i] ;
            if((m1.find(c1) != m1.end() && m1[c1] != c2 ) || 
                (m2.find(c2) != m2.end() && m2[c2] != c1)) return false ;
            m1[c1] = c2 ;
            m2[c2] = c1 ;
        }
        return true ;
    }
}; 