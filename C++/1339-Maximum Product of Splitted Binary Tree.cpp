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
    long long tot = 0, res = 0;
    void dfs(TreeNode* node) {
        tot += node->val;
        if (node->left != nullptr) {
            dfs(node->left);
        }
        if (node->right != nullptr) {
            dfs(node->right);
        }
    }
    long long dfs2(TreeNode* node) {
        
        long long leftVal = 0, rightVal = 0;
        if (node->left != nullptr) {
            leftVal = dfs2(node->left);
        }
        if (node->right != nullptr) {
            rightVal = dfs2(node->right);
        }

        res = max(res, (tot-leftVal)*leftVal);
        res = max(res, (tot-rightVal)*rightVal);

        return node->val + leftVal + rightVal;
    }    

    int maxProduct(TreeNode* root) {
        dfs(root);
        dfs2(root);

        return res%1000000007;
    }
};