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
int ans = 0 ;
    void solve(TreeNode* root , int cnt , char c )
    {
        if(!root) return ;
        ans = max(ans , cnt) ;
        if(c=='l')
        {
            solve(root->left , cnt + 1 , 'r') ;
            solve(root->right , 1 , 'l') ;
        }
        else
        {
            solve(root->right , cnt + 1, 'l') ;
            solve(root->left , 1 , 'r') ;
        }
        return ;
    }
    int longestZigZag(TreeNode* root) {
        solve(root , 0 , 'l') ;
        return ans ;
    }
};