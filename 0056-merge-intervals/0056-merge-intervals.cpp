class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& nums) {
            sort(nums.begin() ,nums.end() ) ;
            vector<vector<int>> result ;
            int n = nums.size() ;
            int i = 0 ; 
            while(i < n)
            {
                int x = nums[i][0] ;
                int y = nums[i][1] ;
                int j = i +1 ;
                while(j < n && nums[j][0] <= y )
                {
                    y = max(y  , nums[j][1] ) ;
                    j++ ;
                }
                result.push_back({x, y }) ;
                i = j ;
            }
            return result ;
    }
};