class Solution {
public:
    int longestBalanced(vector<int>& nums) 
    {
        int n = nums.size()  ;
        int ans = 0 ;
        for(int i = 0 ;  i< n;i++)
        {
            int evecnt =0  , oddcnt = 0 ;
            unordered_set <int> st ;
            for(int j =i ;j<n;j++)
            {   
                if(st.find(nums[j])== st.end()) 
                {
                    if(nums[j] % 2 == 0) evecnt++ ;
                    else oddcnt++ ;
                }
                st.insert(nums[j]) ;
                if(oddcnt == evecnt)
                {
                    ans = max(ans , j - i + 1 ) ;
                }
            }    
        }
        return ans ;
    }
};