class Solution {
public:
vector<vector<int>> directions = {{0,1} ,{1,0} , {0,-1} , {-1,0}} ;

    long long  solve(vector<vector<int>>&grid , int i,int j ,int m ,int n )
    {   
        if(i <0 || j < 0 || i >=m || j >= n  || grid[i][j] == 0 ) return  0 ;
        if(grid[i][j] == -1) return 0 ;
        
        long long sum = grid[i][j] ;
        grid[i][j] = -1 ;
        for(auto dir : directions){
            int newi = i + dir[0] ;
            int newj = j + dir[1] ;
            
            sum += solve(grid ,newi ,newj ,m ,n);
            
        }
        return sum ;
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size() ;
        int n = grid[0].size() ;

        int ans= 0 ;
        for(int i =0;i<m;i++){
            for(int j = 0 ;j<n;j++){
                if(grid[i][j] >0){
                    long long  temp = solve(grid ,i ,j,m,n) ;
                    if(temp%k ==0) ans++ ;
                }
            }
        }
        return ans ;
    }
};