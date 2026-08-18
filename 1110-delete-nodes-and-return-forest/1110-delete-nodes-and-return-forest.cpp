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
vector<TreeNode*> vec ;
set<int>st ;
    TreeNode* solve(TreeNode* root)
    {
        if(!root ) return NULL ;
        root->left = solve(root->left ) ;
        root->right = solve(root->right) ;
        if(st.find(root->val) != st.end())
        {
            if(root->left ) vec.push_back(root->left) ;
            if(root->right) vec.push_back(root->right) ;
            root=NULL ;
        }
        return root;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        if(!root) return {} ;
        for(auto it : to_delete) st.insert(it) ;
        solve(root ) ;
        if(st.find(root->val) ==st.end() ) vec.push_back(root) ;
        return vec ;
    }
};