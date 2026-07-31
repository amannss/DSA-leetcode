class Solution {
public:
    priority_queue<int> mx;
    priority_queue<int, vector<int>, greater<int>> mn;

    unordered_map<int, int> mp;

    int mxSize = 0;
    int mnSize = 0;

    void pruneMx() {
        while (!mx.empty() && mp[mx.top()]) {
            mp[mx.top()]--;
            mx.pop();
        }
    }

    void pruneMn() {
        while (!mn.empty() && mp[mn.top()]) {
            mp[mn.top()]--;
            mn.pop();
        }
    }

    void balance() {
        if (mxSize > mnSize + 1) {
            mn.push(mx.top());
            mx.pop();
            mxSize--;
            mnSize++;
            pruneMx();
        }
        else if (mxSize < mnSize) {
            mx.push(mn.top());
            mn.pop();
            mxSize++;
            mnSize--;
            pruneMn();
        }
    }

    vector<double> medianSlidingWindow(vector<int>& nums, int k) {

        int n = nums.size();

        // First window
        for (int j = 0; j < k; j++) {

            if (mx.empty() || nums[j] <= mx.top()) {
                mx.push(nums[j]);
                mxSize++;
            }
            else {
                mn.push(nums[j]);
                mnSize++;
            }

            balance();
        }

        vector<double> result;

        int i = 0;
        int j = k;

        while (true) {

            pruneMx();
            pruneMn();

            if (k % 2)
                result.push_back(mx.top());
            else
                result.push_back(((double)mx.top() + mn.top()) / 2.0);

            if (j == n)
                break;

            // insert
            if (nums[j] <= mx.top()) {
                mx.push(nums[j]);
                mxSize++;
            }
            else {
                mn.push(nums[j]);
                mnSize++;
            }

            // erase
            mp[nums[i]]++;

            if (nums[i] <= mx.top()) {
                mxSize--;
                if (nums[i] == mx.top())
                    pruneMx();
            }
            else {
                mnSize--;
                if (!mn.empty() && nums[i] == mn.top())
                    pruneMn();
            }

            balance();

            i++;
            j++;
        }

        return result;
    }
};