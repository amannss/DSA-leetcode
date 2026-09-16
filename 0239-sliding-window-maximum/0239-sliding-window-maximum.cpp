class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq ;
        vector<int> result ; int n = nums.size() ;
        for(int i = 0 ; i< n ;i++)
        {
            int maxindex = i - k ; 
            while(!dq.empty() && dq.front() <= maxindex)
            {
                dq.pop_front() ;
            }
            while(!dq.empty() && nums[dq.back()] < nums[i]) dq.pop_back() ;
            dq.push_back(i) ;
            if(i >= k-1 ) result.push_back(nums[dq.front()]) ;
        }
        return result ;
    }
};