class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int i = 0 ; int n = nums.size() ; int j = n-1 ; 
        sort(nums.begin() , nums.end()) ;
        int ans = -1; 
        while(i<j)
        {
            ans = max(ans , nums[i]+nums[j]) ;
            i++ ; j-- ;
        }
        return ans ;
    }
};