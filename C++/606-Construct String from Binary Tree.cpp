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
    string dfs(TreeNode* node){
        if (node == nullptr) return "";
        string s = to_string(node->val);

        if (node->right != nullptr){
            s += "(" + dfs(node->left) + ")";
            s += "(" + dfs(node->right) + ")";
        } else if (node->left != nullptr){
            s += "(" + dfs(node->left) + ")";
        }
        return s;
    }
    
    string tree2str(TreeNode* root) {
        return dfs(root);
    }
};