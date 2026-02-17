class Solution {
public:
int solve(vector<int>&coins ,vector<vector<int>> &dp,int target , int i )
{
    
    if(target == 0) 
    {   
        return 1  ;
    }
    if(i< 0) return 0 ;

    if(dp[i][target] != -1) return dp[i][target] ; 

    int not_take = solve(coins ,dp,target ,i-1) ;
    int take  = 0;
    if(coins[i]<=target )
    {
    take = solve(coins , dp ,target - coins[i] , i )  ;
    }
    return dp[i][target] = take+not_take ;
}
    int change(int amount, vector<int>& coins) {
        int n = coins.size() ;
        
        vector<vector<int>> dp(n+1 , vector<int>(amount + 1 , -1)) ;
        int ans = solve(coins , dp ,amount , n-1) ;
        return ans ;
    }
};