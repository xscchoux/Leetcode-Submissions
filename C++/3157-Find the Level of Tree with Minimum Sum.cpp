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
    int minimumLevel(TreeNode* root) {
        long best = LONG_MAX;
        int res = 1, level = 1;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int length = q.size();
            long tot = 0;
            while (length-- > 0) {
                TreeNode* curr = q.front();
                tot += curr->val;
                q.pop();
                if (curr->left != nullptr) q.push(curr->left);
                if (curr->right != nullptr) q.push(curr->right);
            }
            if (tot < best) {
                best = tot;
                res = level;
            }
            level++;
        }
        return res;
    }
};