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
    int res = 1;
    void dfs(TreeNode* node, int parentVal, int length) {
        int val = node->val;
        if (val == parentVal+1) {
            length++;
            res = max(res, length);
        } else {
            length = 1;
        }

        if (node->left != nullptr) {
            dfs(node->left, val, length);
        }
        if (node->right != nullptr) {
            dfs(node->right, val, length);
        }

    }
    int longestConsecutive(TreeNode* root) {
        dfs(root, 3e4+1, 0);

        return res;
    }
};