class Solution {
public:
    int countSubstrings(string s) 
    {
        int n = s.length() ; int cnt = 0 ;
        vector<vector<bool>> t(n , vector<bool>(n, false)) ;
        for(int l =1 ; l <=n;l++)
        {
            for(int i= 0 ;i + l -1 < n ; i++)
            {
                int j = i + l -1 ;
                if(i==j) // length = 1 
                {
                    t[i][j] = true ; // always an palindrome
                }
                else if(i + 1 == j ) // length = 2
                {
                    t[i][j] = (s[i] == s[j]) ;
                }
                else
                {
                    t[i][j] = ( s[i] == s[j]) && (t[i+1][j-1]) ;
                }
                if(t[i][j] == true ) cnt++ ;
            }
        }
        return cnt ;
    }
};