class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size() ;
        int i = 0; int j = 0 ; 
        int s = 0 ;
        int len = 1e7 ;
        while(j < n )
        {
            s+= nums[j] ;
            while(s>= target  && i <=j )
            {
                s-=nums[i] ;
                len = min(len ,j - i + 1  ) ;
                i++ ;
            }
            j++ ;
        }
        return len == 1e7 ? 0 : len ;
    }
};