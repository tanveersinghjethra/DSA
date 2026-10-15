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
    bool checkTree(TreeNode* root) {
        if(root==NULL)return true;
        if(root->left==NULL && root->right==NULL)return true;
        
        int leftval=0,rightval=0;
        if(root->left){
            leftval=root->left->val;
        }
        
        if(root->right){
            rightval=root->right->val;
        }
        if(root->val!=leftval+rightval)return false;
        return checkTree(root->left)&&checkTree(root->right);
    }
};