
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
    pair<TreeNode*, int> dfs(TreeNode* node) {
        if (node == nullptr) {
            return {nullptr, 0};
        }

        auto [leftNode, leftLen] = dfs(node->left);
        auto [rightNode, rightLen] = dfs(node->right);

        if (leftLen > rightLen) { 
            return {leftNode, leftLen+1};  // {lca of left subtree, length to be returned}
        }
        if (rightLen > leftLen) {
            return {rightNode, rightLen+1}; // {lca of right subtree, length to be returned}
        }

        return {node, leftLen+1};
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return dfs(root).first;      
    }
};