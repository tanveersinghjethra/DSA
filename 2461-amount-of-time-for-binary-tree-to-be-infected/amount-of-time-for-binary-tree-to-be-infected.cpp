class Solution {
public:

    unordered_map<TreeNode*, TreeNode*> parent;

    void inorder(TreeNode* root) {

        if(root == NULL)
            return;

        if(root->left)
            parent[root->left] = root;

        inorder(root->left);

        if(root->right)
            parent[root->right] = root;

        inorder(root->right);
    }

    int BFS(TreeNode* startNode) {

        queue<TreeNode*> q;
        q.push(startNode);

        unordered_set<TreeNode*> visited;
        visited.insert(startNode);

        int time = 0;

        while(!q.empty()) {

            int n = q.size();
            bool infectedNewNode = false;

            while(n--) {

                TreeNode* node = q.front();
                q.pop();

                // Left
                if(node->left != NULL &&
                   !visited.count(node->left)) {

                    q.push(node->left);
                    visited.insert(node->left);
                    infectedNewNode = true;
                }

                // Right
                if(node->right != NULL &&
                   !visited.count(node->right)) {

                    q.push(node->right);
                    visited.insert(node->right);
                    infectedNewNode = true;
                }

                // Parent
                if(parent.count(node) &&
                   !visited.count(parent[node])) {

                    q.push(parent[node]);
                    visited.insert(parent[node]);
                    infectedNewNode = true;
                }
            }

            if(infectedNewNode)
                time++;
        }

        return time;
    }

    TreeNode* findStart(TreeNode* root, int start) {

        if(root == NULL)
            return NULL;

        if(root->val == start)
            return root;

        TreeNode* left = findStart(root->left, start);

        if(left != NULL)
            return left;

        return findStart(root->right, start);
    }

    int amountOfTime(TreeNode* root, int start) {

        if(root == NULL)
            return 0;

        // Build parent map
        inorder(root);

        // Find starting node
        TreeNode* startNode = findStart(root, start);

        // BFS infection
        return BFS(startNode);
    }
};