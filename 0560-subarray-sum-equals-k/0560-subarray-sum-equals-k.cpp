class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size() ;
        int presum  = 0 ;
        unordered_map<int ,int  > mp ;
        int cnt = 0 ;
        for(int i =0;i<n;i++)
        {
            presum+=nums[i] ;
            int r = presum - k;
            if(r== 0) cnt++;  
            cnt+=mp[r] ;
            mp[presum]++ ;
        }
        return cnt ;
    }
};