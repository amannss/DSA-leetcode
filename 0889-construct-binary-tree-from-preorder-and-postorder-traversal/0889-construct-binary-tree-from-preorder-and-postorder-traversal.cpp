class Solution {
public:
    TreeNode* solve(int prestart, int poststart, int preend,
                    vector<int>& preorder, vector<int>& postorder)
    {
        if (prestart > preend)
            return NULL;

        TreeNode* node = new TreeNode(preorder[prestart]);

        // Only one node
        if (prestart == preend)
            return node;

        // Root of left subtree
        int leftRoot = preorder[prestart + 1];

        // Find leftRoot in postorder
        int j = poststart;
        while (postorder[j] != leftRoot)
            j++;

        // Number of nodes in left subtree
        int leftSize = j - poststart + 1;

        // Construct left subtree
        node->left = solve(
            prestart + 1,
            poststart,
            prestart + leftSize,
            preorder,
            postorder
        );

        // Construct right subtree
        node->right = solve(
            prestart + leftSize + 1,
            j + 1,
            preend,
            preorder,
            postorder
        );

        return node;
    }

    TreeNode* constructFromPrePost(vector<int>& preorder,
                                   vector<int>& postorder)
    {
        int n = preorder.size();

        return solve(0, 0, n - 1, preorder, postorder);
    }
};