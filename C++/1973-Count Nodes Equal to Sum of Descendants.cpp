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
    long dfs(TreeNode* node) {
        if (!node) return 0;
        long left = dfs(node->left);
        long right = dfs(node->right);
        if (node->val == left + right) res++;
        return node->val+left+right;
    }
    
    int equalToDescendants(TreeNode* root) {
        dfs(root);
        return res;
    }
};