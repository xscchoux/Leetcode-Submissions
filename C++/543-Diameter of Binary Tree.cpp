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
    int res = 0;
    int dfs(TreeNode* node) {
        if (!node) return -1;
        int l = 1 + dfs(node->left);
        int r = 1 + dfs(node->right);
        res = max(res, l+r);
        return max(l, r);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return res;
    }
};