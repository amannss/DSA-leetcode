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
    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode*> q ;
        if(root!= NULL) q.push(root);
        while(!q.empty())
        {
            int size = q.size() ;
            bool xis = false , yis = false;
            while(size--)
            {   
                
                TreeNode* node= q.front() ; 
                if( node->left != NULL && node->right!=NULL )
                {
                    if(node->left->val == x && node->right->val == y) return false ;
                    else if(node->left->val == y && node->right->val == x) return false ;
                }
                q.pop() ;
                if(node->val==x) xis= true ;
                else if(node->val==y) yis = true ;
                
                    if(node->left ) q.push(node->left) ;
                    if(node->right) q.push(node->right) ;
                
            }
            if(xis && yis) return true ;
        }
        return false ;
    }
};