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
int sum =0 ;
    void solve(TreeNode* root, int cnt )
    {   
        if(!root) return ;
        if(root->left == NULL && root->right==NULL) 
        {
            sum+= cnt*10 + root->val ;
            return ;
        }
        solve(root->left , cnt*10 + root->val) ;
        solve(root->right , cnt*10 + root->val) ;
        return ;
    }

    int sumNumbers(TreeNode* root) {
         solve(root , 0);
         return sum ;
    }
};