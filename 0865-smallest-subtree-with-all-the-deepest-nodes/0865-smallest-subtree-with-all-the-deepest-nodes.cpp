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
typedef pair<TreeNode* , int> p ;
p  inorder(TreeNode* root , int d)
{   
    if(root == NULL) return { NULL , d} ;
    p left = inorder(root->left , d+1);
    p right= inorder(root->right , d+1);
    
    if(left.second == right.second )
    {
        return {root , left.second} ; 
    }
    if(left.second >right.second)
    {
        return left ;
    }
    return right ;
}
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        p x=  inorder(root,0) ;
        return x.first ;
    }
};