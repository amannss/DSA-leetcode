class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int n = original.size() ;
        int mx = 1e9 ;
        vector<vector<int>> vec(26 , vector<int>(26 , mx)) ;
        // make adjacenecy matrix
        for(int i=0;i<n;i++)
        {   
            char val1 = original[i] ; 
            char val2 = changed[i] ;
            int x = val1 - 'a' ;
            int y = val2 - 'a' ;
            vec[x][y] = min(cost[i], vec[x][y]) ;
        }
        // apply floyd warshall and update matrix
        for(int k = 0 ; k < 26 ;k++)
        {
            for(int i = 0 ; i< 26; i++)
            {
                for(int j =0;j<26 ;j++)
                {
                    vec[i][j] = min(vec[i][j] , vec[i][k] + vec[k][j]) ;
                }
            }
        }
        long long result = 0 ;
        for(int i=0;i<source.length();i++)
        {
            if(source[i]== target[i]) continue ;
            char c1 = source[i];
            char c2 = target[i];
            if(vec[c1-'a'][c2-'a'] == mx) return -1 ;
            result+= vec[c1-'a'][c2-'a'];
        }
        return result ;
    }
};