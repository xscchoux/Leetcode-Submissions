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
            return INT_MIN;
        }
        int value = node->val;
        int leftMax = dfs(node->left);
        int rightMax = dfs(node->right);
        
        if (value >= leftMax && value >= rightMax) {
            res++;
        }

        return max({value, leftMax, rightMax});
    }
    int countDominantNodes(TreeNode* root) {
        dfs(root);
        return
    }
};