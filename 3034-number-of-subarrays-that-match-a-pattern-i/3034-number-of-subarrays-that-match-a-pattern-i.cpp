class Solution {
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        vector<int> result ; int ans = 0 ;
        int n = nums.size() ; int m = pattern.size() ;
        for(int i =0;i<n - m ;i++)
        {
            int j = i , k = 0 ;
            while(k<m)
            {
                if(pattern[k] == 1 && nums[j] < nums[j+1] )  {j++ ; k++ ;}
                else if(pattern[k]==0 && nums[j] == nums[j+1]) {j++ ; k++ ;}
                else if(pattern[k] == -1 && nums[j] > nums[j+1]) {j++ ; k++ ;}
                else break ;
                
            }
            if(k>= m) ans++ ;
        }
        return ans ;
    }
};