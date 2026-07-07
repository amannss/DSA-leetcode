class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size() ;
        unordered_map<int , int > mp ;
        mp[0] = -1 ;
        int presum = 0 ;
        int len = 0 ;
        for(int i=0;i<n;i++)
        {   
            if(nums[i] == 0) nums[i] = -1 ; 
            presum+= nums[i] ;
            if(mp.find(presum)!= mp.end() ) // if already present 
            {
                len =  max(len , i - mp[presum]) ;
            }   
            else mp[presum] = i ;
        }
        return len ;
    }
};