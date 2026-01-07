class Solution {
public:
    long long totalSum = 0;
    long long best = 0;
    const int MOD = 1e9 + 7;

    long long getSum(TreeNode* root) {
        if (!root) return 0;
        return root->val + getSum(root->left) + getSum(root->right);
    }

    long long dfs(TreeNode* root) {
        if (!root) return 0;

        long long left = dfs(root->left);
        long long right = dfs(root->right);

        long long subSum = root->val + left + right;

        best = max(best, subSum * (totalSum - subSum));

        return subSum;
    }

    int maxProduct(TreeNode* root) {
        totalSum = getSum(root);   // Step 1: total tree sum
        dfs(root);                 // Step 2: try all splits
        return best % MOD;         // Step 3: modulo at the end
    }
};
