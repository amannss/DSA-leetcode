class Solution {
public:
    int largestVariance(string s) {
        int n = s.length() ;
        vector<bool> c(26 , 0) ;
        int result = 0 ;
        for(char ch : s)
        {
            c[ch - 'a'] = 1 ; // available in string s 
        }
        for(char first = 'a' ; first <= 'z' ; first++)
        {
            for(char second = 'a' ; second <= 'z' ; second++)
            {
                if(c[first-'a']== 0 || c[second - 'a']==0) continue; 

                int firstcnt = 0 ;int secondcnt = 0 ;
                bool check = false ;

                for(char x : s )
                {
                    if(x == first ) firstcnt++ ;
                    if(x == second) secondcnt++ ;
                    if(secondcnt > 0 )
                    {
                        result = max(result  , firstcnt - secondcnt) ;
                    }
                    else
                    {
                        if(check) result = max(result , firstcnt - 1 ) ;
                    }

                    if(secondcnt > firstcnt )
                    {
                        firstcnt = 0 ; 
                        secondcnt = 0 ;
                        check = true ;
                    }
                }
                
            }
        }
        return result ;
    }
};