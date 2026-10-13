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
    void recursion(TreeNode* node,int level ,vector<int>&ans){
        if(node==NULL)return;
        if(level==ans.size()){
            ans.push_back(node->val);
        }
        recursion(node->right,level+1,ans);
        recursion(node->left,level+1,ans);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>res;
        recursion(root,0,res);
        return res;

        // queue<TreeNode*>q;
        // q.push(root);
        // vector<int>ans;
        // if (root == NULL) return ans;
        // while(!q.empty()){
        //     int n=q.size();
        //     for(int i=0;i<n;i++){
        //         TreeNode* node=q.front();
        //         q.pop();
        //         if(i==n-1){
        //             ans.push_back(node->val);
        //         }
        //         if(node->left!=NULL){
        //             q.push(node->left);
        //         }
        //         if(node->right!=NULL){
        //             q.push(node->right);
        //         }
        //     }
        // }
        // return ans;



    }
};