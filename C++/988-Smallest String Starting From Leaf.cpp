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
    string s = "|";
    void dfs(TreeNode* root, string c) {
        if (!root->left && !root->right) {
            s = min(s, char(97 + root->val) + c);
            return;
        }
        if (root->left) dfs(root->left, char(97 + root->val) + c);
        if (root->right) dfs(root->right, char(97 + root->val) + c);
    }
    
    string smallestFromLeaf(TreeNode* root) {
        dfs(root, "");
        return s;
    }
};