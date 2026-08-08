class Solution {
public:
vector<vector<int>> result ;
    void solve(vector<int>&nums , int n,int i , vector<int> temp)
    {
        if( i >=n)
        {
            result.push_back(temp) ;
            return ;
        }
        // take 
        temp.push_back(nums[i]) ;
        solve(nums , n ,i +1 , temp) ;
        temp.pop_back() ;

        // not take 
        solve(nums,n ,i+1, temp ); 
        return ;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n  = nums.size() ;
        vector<int> temp ;
        solve( nums, n , 0 , temp ) ;
        return result ;
    }
};