class Solution {
public:
int  m , n ; 
vector<vector<int>> directions{{0,1} , { 1, 0 } , {-1 , 0} , { 0, -1}} ;
int ans = 0 ;
int no_of_empty =0 ;
void solve(vector<vector<int>> &grid , int cnt ,int i , int j )
{
    if(grid[i][j] == 2 ) {
        if(cnt - 1   == no_of_empty  )   ans++ ;
        return ;
    }
    int temp = grid[i][j] ;
    grid[i][j] = -1;
    for(auto dir : directions)
    {
        int newi = i + dir[0] ;
        int newj = j + dir[1] ;
        if(newi >= 0 && newj>=0 && newi < m && newj<n && grid[newi][newj] != -1)
        {
            solve(grid , cnt+1 , newi , newj ) ;
        }
    }
    grid[i][j] =  temp ;
    return ; 
} 
    int uniquePathsIII(vector<vector<int>>& grid) {
        m = grid.size() ;
        n = grid[0].size() ;
        int s1 , s2 ;
        for(int i = 0 ;  i< m;i++)
        {
            for(int j = 0; j < n;j++)
            {   
                if(grid[i][j] == 1) {s1 = i ; s2 = j ;}
                if(grid[i][j] !=-1 &&  grid[i][j] != 2) no_of_empty++ ;
            }
        }
        solve(grid , 1 , s1 , s2 ) ;
        return ans ;
    }
};