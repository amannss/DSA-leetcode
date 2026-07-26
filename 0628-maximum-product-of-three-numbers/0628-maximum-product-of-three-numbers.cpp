class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin() , nums.end()) ;
        int n = nums.size() ;
        int last = nums[n-1]*nums[n-2]*nums[n-3] ; // 3 +ve may be  largest or
        int first = nums[0]*nums[1]*nums[n-1] ;// 2 -ve and 1 +ve can be largest 
        return max(first , last ) ;
    }
};