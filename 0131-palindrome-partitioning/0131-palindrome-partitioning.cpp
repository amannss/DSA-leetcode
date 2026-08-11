class Solution {
public:
    bool ispalindrome(int start , int end  , string s )
    {
        while(start < end)
        {
            if(s[start++]!= s[end--]) return false;
        }
        return true ;
    }
    void solve(int idx , string&s ,vector<vector<string>>&result, vector<string> path)
    {
        if(idx == s.length())
        {
            result.push_back(path) ;
            return ;
        }
        for(int i = idx ; i<s.length() ;i++)
        {
            if(ispalindrome(idx  , i , s))
            {
                path.push_back(s.substr(idx , i - idx +1  )) ; // length
                solve(i+1 , s , result , path) ;
                path.pop_back() ;
            }
        }
        return ;
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result ;
        vector<string> path ;
        solve(0 , s , result , path) ;
        return result ;
    }
};