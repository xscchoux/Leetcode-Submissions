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

using TIII = tuple<int, int, int>;
class Solution {
public:
    int res = 0;
    TIII dfs(TreeNode* node) {
        if (node == nullptr) {
            return {0, INT_MIN, INT_MAX};  // isSubtree, max, min
        }
        auto [leftSubTreeCount, leftMax, leftMin] = dfs(node->left);
        auto [rightSubTreeCount, rightMax, rightMin] = dfs(node->right);
        int currVal = node->val;
        if (leftSubTreeCount >= 0 && rightSubTreeCount >= 0 && currVal > leftMax && currVal < rightMin) {
            res = max(res, leftSubTreeCount+rightSubTreeCount+1);
            return {leftSubTreeCount+rightSubTreeCount+1, max(currVal, rightMax), min(currVal, leftMin)};
        } else {
            return {-1, -1, -1};
        }
    }
    int largestBSTSubtree(TreeNode* root) {
        // 1. max value in left subtree < current value
        // 2. min value in right subtree > current value
        // 3. both left and right subtrees are BST
      
        dfs(root);

        return res;
    }
};


// Better
using TIII = tuple<int, int, int>;
class Solution {
public:
    int res = 0;
    TIII dfs(TreeNode* node) {
        if (node == nullptr) {
            return {0, INT_MIN, INT_MAX};  // isSubtree, max, min
        }
        auto [leftSubTreeCount, leftMax, leftMin] = dfs(node->left);
        auto [rightSubTreeCount, rightMax, rightMin] = dfs(node->right);
        int currVal = node->val;
        if (currVal > leftMax && currVal < rightMin) {
            res = max(res, leftSubTreeCount+rightSubTreeCount+1);
            return {leftSubTreeCount+rightSubTreeCount+1, max(currVal, rightMax), min(currVal, leftMin)};
        } else {
            return {max(leftSubTreeCount, rightSubTreeCount), INT_MAX, INT_MIN};
        }
    }
    int largestBSTSubtree(TreeNode* root) {
        // 1. max value in left subtree < current value
        // 2. min value in right subtree > current value
      
        return get<0>(dfs(root));
    }
};