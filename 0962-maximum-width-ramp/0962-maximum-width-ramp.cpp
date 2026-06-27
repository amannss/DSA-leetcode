class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n  =nums.size() ; int result = 0 ;
        int i = 0 ; int j= 0;


        vector<int> vec(n, 0 ) ; int maxi = -1 ;
        for(int k = n-1 ; k>=0 ; k--)
        {
            maxi = max(maxi , nums[k]) ;
            vec[k] = maxi ; 
        }
        while(i < n && j < n )
        {
            if(nums[i] <= vec[j])
            {
                result = max(result , j - i ) ;
                j++ ;
            }
            else i++ ;
        }
        return result ;
    }
};