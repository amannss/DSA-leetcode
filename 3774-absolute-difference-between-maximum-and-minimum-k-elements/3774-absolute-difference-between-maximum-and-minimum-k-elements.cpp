class Solution {
public:
    int absDifference(vector<int>& nums, int k) {
        int n = nums.size() ;
        if(nums.size() == k) return 0 ;
        sort(nums.begin() , nums.end()) ;
        int x = accumulate(nums.begin() , nums.begin() + k , 0 ); 
        int y = accumulate(nums.begin() + n-k ,nums.end() , 0); 
        return abs(x - y) ;
    }
};