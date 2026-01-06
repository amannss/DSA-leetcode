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
        queue<TreeNode*> q ;
        int lvl = 0 ;
        int xsum = INT_MIN ;
        int ans ;
        q.push(root) ;
        while(!q.empty())
        {   int sum = 0 ;
            int size = q.size() ;
            while(size--)
            {
                TreeNode* tops = q.front() ;q.pop() ;
                if(tops->left) q.push(tops->left) ;
                if(tops->right) q.push(tops->right) ;
                sum+=tops->val ;
            }
            lvl++ ;
            if(sum > xsum)
            {
                xsum = sum ;ans = lvl ;
            }
        }
        return ans ;
    }
};