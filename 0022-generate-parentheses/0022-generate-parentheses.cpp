class Solution {
public:
    vector<string> result ;
    void solve(int n , string temp ,int open ,int close) 
    {
        if(temp.size()== 2*n)
        {
            result.push_back(temp) ;
            return ;
        }
        if(open < n )
        {
            temp.push_back('(') ;
            solve(n , temp , open +1 , close );
            temp.pop_back() ;
        }
        if(close < open)
        {
            temp.push_back(')') ;
            solve(n , temp , open , close +1 ) ;
            temp.pop_back() ;
        }
        return ;
    }
    vector<string> generateParenthesis(int n) {
        solve(n, "", 0 , 0  ) ;
        return result ;
    }
};