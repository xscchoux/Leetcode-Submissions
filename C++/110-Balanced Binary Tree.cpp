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

// first AC
class Solution {
public:
    bool ans = true;
    int dfs(TreeNode* node) {
        if (node == nullptr) return 0;
        int left = dfs(node->left);
        int right = dfs(node->right);

        if (abs(left-right) > 1) {
            ans = false;
        }
        
        return 1 + max(left, right);
    }
    bool isBalanced(TreeNode* root) {
        dfs(root);

        return ans;
    }
};



// Beter
class Solution {
public:
    int dfs(TreeNode* node, int &height) {
        if (node == nullptr) {
            height = -1;
            return true;
        }
        int left = 0, right = 0;
        if (dfs(node->left, left) && dfs(node->right, right) && abs(right-left) <= 1) {
            height = max(left, right) + 1;
            return true;
        }

        return false;
    }
    bool isBalanced(TreeNode* root) {
        int height = 0;

        return dfs(root, height);
    }
};