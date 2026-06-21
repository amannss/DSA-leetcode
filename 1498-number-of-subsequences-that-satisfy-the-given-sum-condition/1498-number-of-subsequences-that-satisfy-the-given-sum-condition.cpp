class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int mod = 1e9 + 7;

        vector<int> power(n);
        power[0] = 1;
        for (int i = 1; i < n; i++) {
            power[i] = (2LL * power[i - 1]) % mod;
        }

        int l = 0, r = n - 1;
        long long ans = 0;

        while (l <= r) {
            if (nums[l] + nums[r] <= target) {
                ans = (ans + power[r - l]) % mod;
                l++;
            } else {
                r--;
            }
        }

        return ans;
    }
};