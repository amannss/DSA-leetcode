/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
long long sum = 0 ;
long long best =  0 ;
int mod = 1e9 + 7 ;
    long long  totalsum(TreeNode* root)
    {
        if(!root) return 0 ;
        return root->val + totalsum(root->left ) + totalsum(root->right) ;
    }
    long long  solve(TreeNode* root)
    {
        if(!root) return 0 ;
        long long ls = solve(root->left ) ;
        long long rs = solve(root->right) ;
        long long s1 = root->val + ls + rs ;
        long long s2 = sum  -s1 ;
        best = max(best , s1 * s2 ) ;
        return root->val + ls + rs ;

    }
    int maxProduct(TreeNode* root) {
        sum = totalsum(root) ;
        solve(root) ;
        return best % mod ;
    }
};