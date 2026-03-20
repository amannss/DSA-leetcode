class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.length() ;
        int cnt = 0  ; 
        int flip = 0 ;
        
        for(int i= 0 ; i < n  ;i++ )
        {
            if(s[i] == '1' ) { cnt++ ;  }
            else
            {
                flip = min(cnt , flip + 1 ) ;
                
            }
        } 
        return flip ; 
    }
};