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
    int maxLevelSum(TreeNode* root) {
        int level = 1, mxVal = INT_MIN, res = 1;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int sz = q.size(), sum = 0;;
            while (sz-- > 0) {
                auto curr = q.front();
                sum += curr->val;
                q.pop();
                if (curr->left != nullptr) {
                    q.push(curr->left);
                }
                if (curr->right != nullptr) {
                    q.push(curr->right);
                }
            }
            if (sum > mxVal) {
                mxVal = sum;
                res = level;
            }
            level++;
        }

        return res;
    }
};