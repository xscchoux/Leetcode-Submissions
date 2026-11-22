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
    TreeNode* dfs(TreeNode* node, unordered_set<TreeNode*>& visited) {
        if (!node) return nullptr;
        visited.insert(node);
        
        TreeNode* leftNode = nullptr;
        TreeNode* rightNode = nullptr;
        if (node->right) {
            if (visited.find(node->right) == visited.end()) rightNode = dfs(node->right, visited);
            else return nullptr;
        }
        if (node->left){
            leftNode = dfs(node->left, visited);
        }
        node->left = leftNode;
        node->right = rightNode;
        
        return node;
    }
    
    TreeNode* correctBinaryTree(TreeNode* root) {
        unordered_set<TreeNode*> visited;
        return dfs(root, visited);
    }
};




// BFS
class Solution {
public:
    TreeNode* correctBinaryTree(TreeNode* root) {
        // {current node, {parent node, 0 or 1 (from left or right) }}
        unordered_map<TreeNode*, pair<TreeNode*, int>> parent; 

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            auto curr = q.front();
            q.pop();
            if (curr->right != nullptr) {
                if (parent.contains(curr->right)) {
                    auto [node, from] = parent[curr];
                    if (from == 1) {
                        node->right = nullptr;
                    } else {
                        node->left = nullptr;
                    }
                    break;
                }
                parent[curr->right] = {curr, 1};
                q.push(curr->right);
            }
            if (curr->left != nullptr) {
                parent[curr->left] = {curr, 0};
                q.push(curr->left);
            }
        }

        return root;
    }
};