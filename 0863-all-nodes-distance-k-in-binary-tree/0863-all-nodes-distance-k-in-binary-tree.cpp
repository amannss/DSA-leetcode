/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
unordered_map<TreeNode* , TreeNode* > mp ;
    void inorder(TreeNode* root)
    {
        if(!root) return ;
        if(root->left ) mp[root->left] =root ;
        inorder(root->left) ;
        if(root->right) mp[root->right] = root ;
        inorder(root->right) ;
        return ;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        // create parent map
        vector<int> result ;
        inorder(root) ;
        // bfs
        queue<TreeNode*> q ;
        q.push(target ) ;
        set<TreeNode*> visited ;visited.insert(target) ;
        while(!q.empty() && k--)
        {
            int size = q.size() ;
            while(size--)
            {
                TreeNode* node = q.front() ; q.pop() ;
                if(node->left && visited.find(node->left)==visited.end()) 
                {
                    q.push(node->left) ; visited.insert(node->left) ;
                }
                if(node->right && visited.find(node->right) == visited.end()) 
                {
                    q.push(node->right) ; visited.insert(node->right) ;
                }
                if(mp.find(node) != mp.end() && visited.find(mp[node]) == visited.end())
                {
                    q.push(mp[node]) ;
                    visited.insert(mp[node]) ;
                }
            }
        }
        while(!q.empty())
        {
            TreeNode* node = q.front() ; q.pop() ;
            result.push_back(node->val) ;
        }
        return result ;
    }
};