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
int maxsum = -1e7 ;
    int solve(TreeNode* root)
    {
        if(!root) return 0 ;
        int lsum = solve(root->left);
        int rsum = solve(root->right) ;
        int s1 = lsum + rsum + root->val ;
        int s2 = lsum + root->val ;
        int s3 = rsum + root->val ;
        maxsum = max(maxsum ,max(  max(s1 , s2 ), s3 )) ;
        return max( 0 , max(s2 , s3) ) ;
    }
    int maxPathSum(TreeNode* root) {
        solve(root) ;
        return maxsum ;
    }
};