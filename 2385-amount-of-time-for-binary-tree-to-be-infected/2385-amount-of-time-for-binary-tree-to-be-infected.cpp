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
unordered_map<TreeNode* , TreeNode*> mp ;
set<TreeNode*> visited ;
TreeNode* starting ;
    void findparent(TreeNode* root,int val )
    {   
        if(!root) return ;
        if(root->val == val ) starting = root ;
        if(root->left) mp[root->left] = root ;
        findparent(root->left , val) ;
        if(root->right) mp[root->right] = root; 
        findparent(root->right , val) ;
        return ;
    }
    int amountOfTime(TreeNode* root, int start) {   
        findparent(root , start ) ;
        queue<TreeNode*> q ;
        q.push(starting) ;
        visited.insert(starting) ;
        int lvl = 0 ;
        while(!q.empty())
        {
            
            int size = q.size() ;
            while(size--)
            {
                TreeNode* node = q.front() ; q.pop() ;
                if(node->left && visited.find(node->left) == visited.end()) {
                    q.push(node->left);visited.insert(node->left) ;
                } 
                if(node->right && visited.find(node->right) == visited.end()) {
                    q.push(node->right);visited.insert(node->right) ;
                } 
                if(mp.find(node) != mp.end() && visited.find(mp[node]) == visited.end())
                {
                    q.push(mp[node]) ; visited.insert(mp[node]) ;
                }
            }
            if(!q.empty()) lvl++ ;
        }
        return lvl;
    }
};