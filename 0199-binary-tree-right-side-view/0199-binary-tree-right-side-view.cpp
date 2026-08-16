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
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {} ;
        vector<int > result ;
        queue<TreeNode*> pq;
        pq.push(root) ;

        while(!pq.empty())
        {
            int size = pq.size() ;
            while(size>0)
            {
                TreeNode* p = pq.front() ;
                if(p->left!=NULL) pq.push(p->left );
                if(p->right!=NULL) pq.push(p->right) ;
                if(size == 1){   result.push_back(p->val) ; }
                size-- ;
                pq.pop() ;
            }
        }
        return result ;
    }
};