class Solution {
public:
    int compress(vector<char>& chars) {
        int i =0 ; int j = 0 ;int n = chars.size() ;
        char curr   ;
        int cnt = 0 ;
        while(i < n)
        {   
            cnt = 0 ; 
            curr = chars[i] ;
            // count duplicates 
            while(i < n && chars[i] == curr )
            {
                i++ ; cnt++ ;
            }
            chars[j] = curr ;
            j++ ;

            if(cnt > 1)
            {
                string t= to_string(cnt) ; 
                for(char c : t)
                {
                    chars[j] = c ;
                    j++ ;
                }
            }
           
        }
        return j ; 
    }
};