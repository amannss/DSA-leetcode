class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> result ;
        int n = nums.size() ;
        for(int i= 0 ; i < n ;i++)
        {
            int ind  = abs(nums[i]) ;
            ind--;
            if(nums[ind] >= 0) nums[ind] = -nums[ind] ;
        }
        for(int i = 0 ; i < n ;i++)
        {
            if(nums[i] >=0 ) result.push_back(i+1) ;
        }
        return result ;
    }
};