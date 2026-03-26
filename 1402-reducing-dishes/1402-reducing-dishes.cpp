class Solution {
public:
    int solve(vector<int>& vec, int i,int cnt , vector<vector<int>> &dp)
    {
        if(i >= vec.size()) return 0 ;
        if(dp[i][cnt] != -1 ) return dp[i][cnt] ;
        int take =vec[i]*cnt +  solve(vec , i+1 ,cnt + 1 ,dp) ;
        int not_take  = solve(vec , i+1 , cnt,dp ) ;
        return dp[i][cnt] = max(take , not_take ) ;
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size() ;
        vector<vector<int>> dp(n, vector<int>(n+1,-1 )) ;
        sort(satisfaction.begin() , satisfaction.end() ) ;
        return solve(satisfaction , 0 , 1 ,dp) ;
    }
};