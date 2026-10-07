class Solution {
public:

    int check(TreeNode* root) {

        if (root == NULL)
            return 0;

        int Lh = check(root->left);

        if (Lh == -1)
            return -1;

        int Rh = check(root->right);

        if (Rh == -1)
            return -1;

        if (abs(Lh - Rh) > 1)
            return -1;

        return max(Lh, Rh) + 1;
    }

    bool isBalanced(TreeNode* root) {

        return check(root) != -1;
    }
};