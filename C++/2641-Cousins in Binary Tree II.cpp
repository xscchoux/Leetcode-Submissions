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
    TreeNode* replaceValueInTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int tot = root->val;
        while (!q.empty()) {
            int size = q.size();
            int nxtTot = 0;
            while (size-- > 0) {
                TreeNode* curr = q.front();
                q.pop();
                curr->val = tot - curr->val;
                int sameParentSum = (curr->left != nullptr?curr->left->val:0) + (curr->right != nullptr?curr->right->val:0);
                if (curr->left) {
                    nxtTot += curr->left->val;
                    curr->left->val = sameParentSum;
                    q.push(curr->left);
                }
                if (curr->right) {
                    nxtTot += curr->right->val;
                    curr->right->val = sameParentSum;
                    q.push(curr->right);
                }
            }
            tot = nxtTot;
        }
        return root;
    }
};