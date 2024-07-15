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
    TreeNode* getLCA(TreeNode* node, int p, int q) {
        if (node == nullptr) return nullptr;
        if (node->val == p || node->val == q) return node;
        
        TreeNode* node1 = getLCA(node->left, p, q);
        TreeNode* node2 = getLCA(node->right, p, q);

        if (node1 != nullptr && node2 != nullptr) return node;
        else return (node1 == nullptr)?node2:node1;
    }
    int getDistance(TreeNode* node, int target) {
        if (node == nullptr) return INT_MAX/2;
        if (node->val == target) return 0;

        return 1 + min(getDistance(node->left, target), getDistance(node->right, target));
    }
    int findDistance(TreeNode* root, int p, int q) {
        TreeNode* LCA = getLCA(root, p, q);

        int pd = getDistance(LCA, p), qd = getDistance(LCA, q);

        return pd + qd;
    }
};