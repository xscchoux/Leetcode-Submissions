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
        if (node == nullptr) {
            return 0;
        }
        int left = dfs(node->left);
        int right = dfs(node->right);
        res += abs(left) + abs(right);

        return left + right + node->val - 1;  // how many coins we need (negative) or move out (positive) to make all nodes in the subtree have one coin
    }
    int distributeCoins(TreeNode* root) {
        dfs(root);
        return res;
    }
};