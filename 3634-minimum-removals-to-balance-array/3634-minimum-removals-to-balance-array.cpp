class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int i = 0, j = 1;
        int maxi = 1;

        while (j < n) {
            while (i < j && 1LL * nums[i] * k < nums[j]) {
                i++;
            }
            maxi = max(maxi, j - i + 1);
            j++;
        }

        return n - maxi;
    }
};