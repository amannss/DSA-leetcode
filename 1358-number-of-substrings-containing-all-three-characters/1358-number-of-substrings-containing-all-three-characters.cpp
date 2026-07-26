class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> c = {-1,-1,-1} ;
        int n = s.length() ;
        int cnt =0 ;
        for(int i= 0 ; i < n ;i++)
        {
            c[s[i]- 'a'] = i ;// lastseen index 

            if(c[0]!= -1 && c[1] != -1 && c[2] != -1)
            {
                cnt +=  1 + min({c[0] , c[1]  , c[2]}) ;
            }
        }
        return cnt ;
    }
};