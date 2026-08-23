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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode* > q ;
        if(root) q.push(root) ;
        int ans ;
        int bestsum= -1e9;
        int lvl = 0 ;
        while(!q.empty())
        {
            int sum = 0 ;
            int size = q.size() ;
            lvl++ ;
            while(size--)
            {
                TreeNode* node = q.front() ; q.pop() ;
                sum+= node->val ;
                if(node->left ) q.push(node->left) ;
                if(node->right) q.push(node->right) ;
            }
            if(sum > bestsum ) {ans = lvl; bestsum = sum ; } 
        }
        return ans; 
    }
};