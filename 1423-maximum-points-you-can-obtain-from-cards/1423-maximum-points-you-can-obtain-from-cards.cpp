class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int l = n - k;

        int sum = accumulate(cardPoints.begin(), cardPoints.end(), 0);

        if (l == 0) return sum;

        int temp = 0;
        int i = 0, j = 0;

        while (j < l) {
            temp += cardPoints[j++];
        }

        int ans = sum - temp;

        while (j < n) {
            temp -= cardPoints[i++];
            temp += cardPoints[j++];
            ans = max(ans, sum - temp);
        }

        return ans;
    }
};