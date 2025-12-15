class Solution {
public:
    vector<int> countOfPairs(int n, int x, int y) {
        int mx = 1e7 ;
        vector<vector<int>> vec(n+1 , vector<int>(n+1 , mx )) ;
        for(int i = 1 ; i< n; i++)
        {
            vec[i][i+1] = 1 ;
            vec[i+1][i] = 1 ;
        }
        vec[x][y] = 1 ;
        vec[y][x] = 1 ;

        for(int k = 1 ; k<n+1;k++)
        {
            for(int i=1;i<n+1;i++)
            {
                for(int j =1;j < n+1;j++)
                {   
                    if(i==j) continue ;
                    vec[i][j] = min(vec[i][j] , vec[i][k]+vec[k][j]) ;
                }
            }
        }
        vector<int> result(n+1,0) ;
        for(int i = 1 ; i<n+1;i++)
        {
            for(int j = 1;j < n+1;j++)
            {
                if(i==j) continue ;
                result[vec[i][j]]++ ;
            }
        }
        result.erase(result.begin()) ;
        return result ;
    }
};