class Solution {
public:
    int solve(vector<int>&nums , int i , int n, vector<int> &dp)
    {
        if(i>= n ) return 0; 
        if(dp[i] != -1 ) return dp[i] ;
        return dp[i] =  max(nums[i] + solve(nums , i+2 ,n ,dp ) ,  solve(nums ,i+1 ,n ,dp)) ;
    }
    int r(vector<int>& nums) {
        int n = nums.size() ;
        vector<int> dp(n+1 , -1 ) ;
        return solve(nums, 0 ,n, dp) ;
    }
    int rob(vector<int>& nums) {
        int n = nums.size() ;
        if(n == 1 ) return nums[0] ;
        vector<int> temp(nums.begin() , nums.end() - 1) ;
        int first = r(temp) ;
        vector<int> temp2(nums.begin() +1 , nums.end()) ;
        int second = r(temp2) ;
        return max(first , second );
    }
};