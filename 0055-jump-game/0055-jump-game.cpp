class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size() ;
        int i = 1 ;
        int index = nums[0]  ;
        while(i < n )
        {   
            if(i > index ) return false ;
            if((nums[i] + i ) > index)  index= nums[i] + i ; 
            i++ ;
        }
        return true ;
    }
};