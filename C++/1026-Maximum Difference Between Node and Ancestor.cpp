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
    int maxAncestorDiff(TreeNode* root) {
        int curr = root->val;
        helper(root, curr, curr);
        return res;
    }
    
    void helper(TreeNode* node, int maxVal, int minVal) {
        int curr = node->val;
        maxVal = max(maxVal, curr);
        minVal = min(minVal, curr);
        res = max(maxVal-minVal, res);
        if (node->left) helper(node->left, maxVal, minVal);
        if (node->right) helper(node->right, maxVal, minVal);
    }
};