class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();

        int i = 0;       // Next position for 0
        int j = 0;       // Current element
        int k = n - 1;   // Next position for 2

        while (j <= k) {
            if (nums[j] == 0) {
                swap(nums[i], nums[j]);
                i++;
                j++;
            }
            else if (nums[j] == 1) {
                j++;
            }
            else { // nums[j] == 2
                swap(nums[j], nums[k]);
                k--;
            }
        }
    }
};