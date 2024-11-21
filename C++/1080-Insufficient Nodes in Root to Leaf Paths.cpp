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

// First try
class Solution {
public:
    int dfs(TreeNode* node, int limit, int tot) {
        if (node == nullptr) return INT_MIN;

        int leftMax = dfs(node->left, limit, tot + node->val);
        int rightMax = dfs(node->right, limit, tot + node->val);

        if (node->left != nullptr && tot + node->val + leftMax < limit) {
            node->left = nullptr;
        }
        if (node->right != nullptr && tot + node->val + rightMax < limit) {
            node->right = nullptr;
        }

        return node->val + (max(leftMax, rightMax) == INT_MIN?0:max(leftMax, rightMax));
    }
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        TreeNode* parent = new TreeNode(0);
        parent->left = root;
        dfs(parent, limit, 0);

        return parent->left;
    }
};


// Really smart solution
class Solution {
public:
    TreeNode* dfs(TreeNode* node, int limit) {
        if (node->left == nullptr && node->right == nullptr) {
            if (node->val < limit) return nullptr;
            return node;
        }

        if (node->left != nullptr) {
            node->left = dfs(node->left, limit-node->val);
        }
        if (node->right != nullptr) {
            node->right = dfs(node->right, limit-node->val);
        }        

        if (node->left == nullptr && node->right == nullptr) return nullptr; // cannot create a path to leaf
        return node;
    }
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        return dfs(root, limit);        
    }
};