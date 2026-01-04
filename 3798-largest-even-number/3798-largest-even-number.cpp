class Solution {
public:
    string largestEven(string s) {
        int n = s.length();
        string x = "" ;
        for(int j = n-1 ; j >=0 ; j-- )
        {
            if(s[j]=='2') return s ;
            else 
            {
                s.pop_back() ;
            }
        }
        return  x;
    }
};