class Solution {
public:
unordered_map<char , string> mp ;
    void solve(int idx , vector<string>& result , string path,string digits )
    {
        if(idx>=digits.length() )
        {
            result.push_back(path) ;
            return ;
        }
        string ch = mp[digits[idx]] ;
        for(auto c : ch)
        {
            path.push_back(c) ;
            solve(idx+ 1, result , path , digits ) ;
            path.pop_back() ;
        }
        return ;
    }
    vector<string> letterCombinations(string digits) {
        vector<string> result ;
        string path="" ;
        mp['2'] ="abc" ;
        mp['3'] ="def" ;
        mp['4'] ="ghi" ;
        mp['5'] ="jkl" ;
        mp['6'] ="mno" ;
        mp['7'] ="pqrs";
        mp['8'] ="tuv" ;
        mp['9'] ="wxyz";

        solve(0 , result  , path , digits) ;
        return result ;
    }
};