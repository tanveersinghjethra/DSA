class Solution {
public:

    int search(vector<int> inorder, int left, int right, int val) {
        for(int i = left; i <= right; i++) {
            if(inorder[i] == val) {
                return i;
            }
        }
        return -1;
    }

    TreeNode* helper(vector<int>& preorder, vector<int>& inorder,
                     int& preIdx, int left, int right) {

        // Invalid range
        if(left > right) {
            return NULL;
        }

        // Create root from preorder
        TreeNode* root = new TreeNode(preorder[preIdx]);

        // Find root in inorder
        int inIdx = search(inorder, left, right, preorder[preIdx]);

        preIdx++;

        // Build left subtree
        root->left = helper(preorder, inorder, preIdx, left, inIdx - 1);

        // Build right subtree
        root->right = helper(preorder, inorder, preIdx, inIdx + 1, right);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preIdx = 0;

        return helper(preorder, inorder, preIdx,
                      0, inorder.size() - 1);
    }
};