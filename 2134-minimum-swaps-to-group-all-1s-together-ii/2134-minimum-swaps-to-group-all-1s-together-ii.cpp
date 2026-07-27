class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size() ;
        int i  =0 , j  = 0 ;
        int len = 0 ; // this will be the size of window 
        for(auto it : nums ) {if(it == 1 )len++ ;}
        nums.insert(nums.end() , nums.begin() ,nums.end()) ;
        int ans = 0 ;
        int cnt = 0 ; // count of 0 
        while( j <  len )
        {
            if(nums[j++] == 0) cnt++ ;
        }
        ans = cnt ;
        n =  2*  n ;
        while(j  < n)
        {
            if(nums[i++] == 0) cnt-- ;
            if(nums[j++]==0) cnt++ ;
            ans = min(ans , cnt) ;
        }
        return ans ;
    }
};