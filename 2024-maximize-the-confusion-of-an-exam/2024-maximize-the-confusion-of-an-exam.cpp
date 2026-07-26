class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
            string s = answerKey ;
            int n  = s.length() ;
            int i =0, j = 0 ;
            int cntt =0 , cntf =0 ;
            int ans= 0 ;
            while(j < n)
            {
                if(s[j] =='T') cntt++ ;
                else cntf++ ;
                while((min(cntt , cntf) > k) && i <=j)
                {
                    if(s[i] == 'T') cntt-- ;
                    else cntf-- ;
                    i++ ;
                }
                ans = max(ans , j-i+1) ;
                j++ ;
            }
            return ans ;
    }
};