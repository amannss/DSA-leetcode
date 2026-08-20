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
    int maxnum(vector<int> & nums,int i , int j )
    {   
        int maxi = i;
        for(int  k = i ; k < j ;k++)
        {
            if(nums[k]>nums[maxi]) maxi = k ;
        }
        return  maxi ;
    }
    TreeNode* solve(vector<int>& nums ,int i , int j )
    {   
        if(i>=j) return NULL ;
        int maxi = maxnum(nums , i , j ) ;
        TreeNode* node=  new TreeNode(nums[maxi]) ;
        node->left = solve(nums ,i , maxi) ;
        node->right = solve(nums , maxi+1 , j) ;
        return node ;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return solve(nums, 0 , nums.size()) ;
    }
};