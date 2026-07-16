class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int i = 0, j = 0;
        int n = nums.size();
        int s = 0;

        while (j < k) {
            s += nums[j++];
        }

        double result = (double)s / k;

        while (j < n) {
            s -= nums[i++];
            s += nums[j++];
            result = max(result, (double)s / k);
        }

        return result;
    }
};