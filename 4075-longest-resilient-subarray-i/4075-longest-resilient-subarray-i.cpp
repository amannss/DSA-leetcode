class Solution {
public:
    int resilientSubarray(vector<int>& nums, int k) {
        int maxlen  = 1 ;
        int len = 1 ;int n = nums.size() ;
        for(int i = 1 ; i<n;i++)
        {   
            int r = nums[i]%k ;
            if(r ==  nums[i-1]%k )
            {
                len++ ;
            }
            else{
                len = 1;
            }

            if(  ((len -1 ) * r )%k == 0   )
            maxlen = max(maxlen , len) ;
        }
        return maxlen ;
    }
};