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
    int findroot(vector<int> inorder , int val,int s, int e)
    {   
        int i ;
        for(i = s ;i <= e;i++)
        {
            if(inorder[i] == val) break; 
        }
        return i; 
    }
    TreeNode* solve(vector<int >&inorder ,vector<int>& postorder ,int instart ,int inend , int poststart, int postend)
    {   
         if (instart > inend || poststart > postend) return NULL;
        TreeNode * node = new TreeNode(postorder[postend]) ;
        int i  = findroot(inorder , postorder[postend] , instart , inend) ;
        int leftlength = i  - instart ;
        int rightlength= inend - i ;
        node->left = solve(inorder , postorder , instart , i-1 , poststart ,poststart + leftlength -1 ) ;
        node->right = solve(inorder , postorder , i+1  , inend , postend - rightlength ,postend-1 ) ;
        return node ;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size() ;
        return solve(inorder , postorder , 0 , n-1 , 0 , n-1  ) ;
    }
};