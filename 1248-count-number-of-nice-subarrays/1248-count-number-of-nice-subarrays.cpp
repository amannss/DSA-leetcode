class Solution {
public:
    int atmost(vector<int>&nums, int k)
    {
        int n= nums.size() ; 
        int i =0 , j = 0 ;
        int cnt = 0 ;
        int ans = 0 ;
        while(j < n)
        {
            if(nums[j] % 2 != 0 )
            {
                cnt++ ;
            }
            while(cnt > k && i  <= j)
            {
                if(nums[i] % 2 != 0 ) cnt-- ;
                i++ ;
            }
            ans+= j - i +1 ;
            j++;
        }
        return ans; 
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atmost(nums, k ) - atmost(nums , k -1 ) ;
    }
};