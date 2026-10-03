class Solution {
public:

    int longestValidParentheses(string s) {
        int n = s.length() ;int ans =0 , cnt = 0 ;int j = -1 ;
        for(int i =0;i<n;i++)
        {
            if(s[i]=='(') cnt++ ;
            else cnt-- ;

            if(cnt < 0 ){
                j = i ; 
                cnt = 0 ;
            } 
            else if(cnt == 0) {
                ans = max(ans , i-j) ;
            }
        }
        j =n ;
        cnt = 0 ;
        for(int i =n -1 ;i>=0;i--)
        {
            if(s[i]==')') cnt++ ;
            else cnt-- ;

            if(cnt < 0 ){
                j = i ; 
                cnt = 0 ;
            } 
            else if(cnt == 0) {
                ans = max(ans , j-i) ;
            }
        }
        return ans ;
    }
};