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
    unordered_map<string , int > mp ;
    string solve(TreeNode* root , vector<TreeNode*>& result )
    {
        if(!root) return "N" ;
        string x ;
        string s = to_string(root->val)  + "," + solve(root->left,result ) + "," + solve(root->right,result) ;
        if(mp[s]== 1) result.push_back(root) ;
        mp[s]++ ;
        return s ;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> result ;
        solve(root , result ) ;
        return result ;
    }
};