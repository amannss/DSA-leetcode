class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = -1;   // Handles subarrays starting from index 0

        int presum = 0;

        for (int i = 0; i < nums.size(); i++) {
            presum += nums[i];
            int rem = presum % k;

            if (mp.find(rem) != mp.end()) {
                if (i - mp[rem] >= 2)
                    return true;
            } else {
                // Store only the first occurrence
                mp[rem] = i;
            }
        }

        return false;
    }
};