class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.length() ;
        string ans ="" ;
        int open = 0 , close = 0;
        for(int i = 0 ; i < n;i++)
        {   
            if(s[i] == '(') open++ ;
            else close++ ;


            
            if(open == close) {
                open = 0 ; close = 0 ;
                continue ;
            }
            if(open == 1 ) continue ;
            ans.push_back(s[i]) ;
        }
        return ans ;
    }
};