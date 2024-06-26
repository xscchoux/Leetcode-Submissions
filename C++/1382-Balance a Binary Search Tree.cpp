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
    vector<int> allNodes;
    void dfs(TreeNode* node) {
        if (node == nullptr) return;
        dfs(node->left);
        allNodes.push_back(node->val);
        dfs(node->right);
    }
    TreeNode* construct(int left, int right) {
        if (left > right) return nullptr;
        if (left == right) return new TreeNode(allNodes[left]);
        int mid = left + (right-left)/2;

        return new TreeNode(allNodes[mid], construct(left, mid-1), construct(mid+1, right));
    }
    TreeNode* balanceBST(TreeNode* root) {
        dfs(root);
        return construct(0, allNodes.size()-1);
    }
};