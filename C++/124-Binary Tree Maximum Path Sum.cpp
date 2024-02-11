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
    int res = INT_MIN;
    int dfs(TreeNode* node) {
        if (!node) return 0;
        int leftVal = 0, rightVal = 0;
        leftVal = max(leftVal, dfs(node->left));
        rightVal = max(rightVal, dfs(node->right));
        res = max(res, node->val + leftVal + rightVal);
        
        return max(node->val + leftVal, node->val + rightVal);
    }
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return res;
    }
};