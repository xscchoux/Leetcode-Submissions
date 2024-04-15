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
    int tot = 0;
    void dfs(TreeNode* node, int value) {
        value = value*10 + node->val;
        if (node->left == nullptr && node->right == nullptr) {
            tot += value;
            return;
        }
        if (node->left) dfs(node->left, value);
        if (node->right) dfs(node->right, value);
    }
    
    int sumNumbers(TreeNode* root) {
        dfs(root, 0);
        return tot;
    }
};