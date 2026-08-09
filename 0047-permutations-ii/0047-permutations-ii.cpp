class Solution {
public:
set<vector<int>> result ;
unordered_set<int > st ;
    void solve(vector<int>& nums  , int n , vector<int> temp )
    {
        if(temp.size() == n )
        {
            result.insert(temp) ;
            return ;
        }
        for(int i =0 ; i < n ;i++)
        {
            if(st.find(i) == st.end() ) 
            {
                st.insert(i);
                temp.push_back(nums[i]) ;
                solve(nums , n ,temp) ;
                st.erase(i) ;
                temp.pop_back() ;
            }
        }
        return ;
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
         int n = nums.size() ;
        vector<int> temp ;
        solve(nums ,  n , temp) ;
        vector<vector<int>> ans ;
        for(auto it : result) ans.push_back(it) ;
        return ans ;
    }
};