class Solution {
public:
int n  ;
vector<vector<int>> result ;
    void solve(int idx , vector<int>&nums, vector<int> temp)
    {   
        if(temp.size() >= 2 ) result.push_back(temp) ;
        unordered_set<int> st ;
        for(int i = idx ; i < n ; i++ )
        {
            if( (temp.empty() || temp.back() <= nums[i]) && st.find(nums[i]) == st.end() )
            {
                temp.push_back(nums[i]) ;
                solve(i +1 , nums , temp) ;
                temp.pop_back() ;
                st.insert(nums[i]) ;
            }
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        n = nums.size() ;
        vector<int> temp ;
        solve(0 , nums , temp ) ;
        return result ;
    }
};