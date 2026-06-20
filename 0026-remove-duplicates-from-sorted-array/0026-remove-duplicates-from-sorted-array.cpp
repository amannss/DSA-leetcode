class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size() ;
        int i = 0, j =0 ; 
        while(i < n && j < n )
        {
            if(nums[i] != nums[j])
            {
                j++ ;
                nums[j] = nums[i] ;
            }
            i++;
        }
        int ans = j - 0 + 1 ;
        return ans ;
    }
};