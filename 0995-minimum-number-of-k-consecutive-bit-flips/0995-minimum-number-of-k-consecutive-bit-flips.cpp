class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size() ;
        unordered_map<int ,int> mp ;
        int result =0 ;int flipcnt = 0 ;
        for(int i =0 ;i <n;i++)
        {
            if( i>= k && mp.find(i-k) != mp.end())
            {
                flipcnt-- ; // not valid subarrqay means current idx out of last subarray
            }
            if( ( flipcnt%2==0 && nums[i] == 1 ) || (flipcnt %2!= 0 && nums[i]== 0)) continue ;
            else 
            {   
                if(i + k > n) return -1 ;
                result++ ; flipcnt++ ;mp[i] =1 ;
            }
        }
        return result ;
    }
};