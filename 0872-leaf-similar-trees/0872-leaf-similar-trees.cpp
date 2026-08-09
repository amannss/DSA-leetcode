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
    void inorder(vector<int>&vec , TreeNode* root)
    {   
        if(!root) return ;
        if(root->left ==NULL && root->right == NULL)
        {
            vec.push_back(root->val) ;
            return ;
        }
        inorder(vec, root->left) ;
        inorder(vec,root->right) ;
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> v1 ; 
        inorder(v1, root1) ;
        vector<int> v2 ;
        inorder(v2 ,root2) ;
        if(v1.size() != v2.size() ) return false ;
        for(int i = 0; i < v1.size() ;i++) if(v1[i] != v2[i]) return false ;
        return true ;
    }
};