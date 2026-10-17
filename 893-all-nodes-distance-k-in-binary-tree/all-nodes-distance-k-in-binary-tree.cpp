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

    unordered_map<TreeNode*, TreeNode*> parent;

    void inorder(TreeNode* root) {
        if(root == NULL)
            return;

        if(root->left) {
            parent[root->left] = root;
        }

        inorder(root->left);

        if(root->right) {
            parent[root->right] = root;
        }

        inorder(root->right);
    }

    void BFS(TreeNode* target, int k, vector<int>& ans) {

        queue<TreeNode*> q;
        q.push(target);

        unordered_set<TreeNode*> visited;
        visited.insert(target);

        while(!q.empty()) {

            int n = q.size();

            if(k == 0)
                break;

            while(n--) {

                TreeNode* node = q.front();
                q.pop();

                // Left child
                if(node->left != NULL &&
                   !visited.count(node->left)) {

                    q.push(node->left);
                    visited.insert(node->left);
                }

                // Right child
                if(node->right != NULL &&
                   !visited.count(node->right)) {

                    q.push(node->right);
                    visited.insert(node->right);
                }

                // Parent
                if(parent.count(node) &&
                   !visited.count(parent[node])) {

                    q.push(parent[node]);
                    visited.insert(parent[node]);
                }
            }

            k--;
        }

        // All nodes currently in queue are distance k
        while(!q.empty()) {

            TreeNode* node = q.front();
            q.pop();

            ans.push_back(node->val);
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

        vector<int> ans;

        // Step 1: Create parent mapping
        inorder(root);

        // Step 2: BFS from target
        BFS(target, k, ans);

        return ans;
    }
};