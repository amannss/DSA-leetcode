class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        unordered_map<int , int > mp ;
        int n = nums.size() ;
        if(n == 1 ) return true ;
        int m = n /2 ;
        int mid = nums[m] ;
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++ ;
            if(mp[mid] > 1 ) return false ;
        }
        return true ;
    }
};