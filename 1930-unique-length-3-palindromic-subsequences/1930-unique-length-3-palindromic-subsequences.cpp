class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_set<char> letters;
        for(auto c : s) letters.insert(c) ;
        int n = s.length() ;
        int i=0 ;
        int cnt = 0 ;
        for(auto c : letters)
        {
            int lindex = -1  , rindex = -1 ;
            for(int i =0 ;i<n;i++)
            {   
                char  d = s[i] ;    
                if(d==c)
                {   
                    if(lindex == -1) { lindex = i ;rindex =i ; }
                    else rindex = i ;
                } 
            }
            unordered_set<char > st ;
            for(int j = lindex+ 1 ; j <= rindex -1 ;j++ )
            {
                st.insert(s[j]) ;
            }
            if(lindex + 1 <= rindex  )
            {
                cnt += st.size() ;
            }
        }
        return cnt ;
        
    }
};