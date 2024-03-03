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
    int res;
    int maxDepth = 0;
    void dfs(TreeNode* node, int depth) {
        if (!node) return;
        if (depth > maxDepth) {
            maxDepth = depth;
            res = node->val;
        }
        dfs(node->left, depth+1);
        dfs(node->right, depth+1);
    }
    int findBottomLeftValue(TreeNode* root) {
        this->res = root->val;
        dfs(root, 0);
        return res;
    }
};