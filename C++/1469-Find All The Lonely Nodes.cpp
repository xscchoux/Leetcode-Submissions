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
    vector<int> res;
    void dfs(TreeNode* node, int count) {
        if (count == 1) res.push_back(node->val);
        
        if (node->left && node->right) count = 2;
        else count = 1;
        
        if (node->left) dfs(node->left, count);
        if (node->right) dfs(node->right, count);
    }
    
    vector<int> getLonelyNodes(TreeNode* root) {
        dfs(root, 0);
        return res;
    }
};