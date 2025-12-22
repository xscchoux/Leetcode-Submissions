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
    pair<int, int> dfs(TreeNode* node) {
        int leftIncreasing = 0, leftDecreasing = 0, rightIncreasing = 0, rightDecreasing = 0;
        if (node->left != nullptr) {
            auto [inc, dec] = dfs(node->left);
            if (node->val == node->left->val + 1) {
                leftIncreasing = inc;
            }
            if (node->val == node->left->val - 1) {
                leftDecreasing = dec;
            }
        }
        if (node->right != nullptr) {
            auto [inc, dec] = dfs(node->right);
            if (node->val == node->right->val + 1) {
                rightIncreasing = inc;
            }
            if (node->val == node->right->val - 1) {
                rightDecreasing = dec;
            }
        }

        res = max({res, leftIncreasing + 1 + rightDecreasing, rightIncreasing + 1 + leftDecreasing});

        return {max(1+leftIncreasing, 1+rightIncreasing), max(1+leftDecreasing, 1+rightDecreasing)};
    }
    int longestConsecutive(TreeNode* root) {
        dfs(root);

        return res;
    }
};



// Better
class Solution {
public:
    int res = 1;
    pair<int, int> dfs(TreeNode* node) {
        int increasing = 0, decreasing = 0;
        if (node->left != nullptr) {
            auto [inc, dec] = dfs(node->left);
            if (node->val == node->left->val + 1) {
                increasing = inc;
            }
            if (node->val == node->left->val - 1) {
                decreasing = dec;
            }
        }
        if (node->right != nullptr) {
            auto [inc, dec] = dfs(node->right);
            if (node->val == node->right->val + 1) {
                increasing = max(increasing, inc);
            }
            if (node->val == node->right->val - 1) {
                decreasing = max(decreasing, dec);
            }
        }

        res = max(res, increasing + 1 + decreasing);

        return {1+increasing, 1+decreasing};
    }
    int longestConsecutive(TreeNode* root) {
        dfs(root);

        return res;
    }
};