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
typedef pair<int , int > p ;
int ans = 0 ;
    p solve(TreeNode* root)
    {
        if(!root) return {0,0} ;
        p left = solve(root->left) ;
        p right = solve(root->right) ;
        int sum = root->val + left.first + right.first ;
        int num = 1 + left.second + right.second ;
        if(sum / num == root->val) ans++ ;
        return {sum , num} ;
    }
    int averageOfSubtree(TreeNode* root) {
        solve(root) ;
        return ans;
    }
};