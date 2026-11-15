/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    // state: 2:found both, 1: fount 1, 0: null
    pair<TreeNode*, int> dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) {
            return {nullptr, 0};
        }
        int pVal = p->val, qVal = q->val, rootVal = root->val;
        auto [leftNode, leftState] = dfs(root->left, p, q);
        auto [rightNode, rightState] = dfs(root->right, p, q);

        if (leftState == 2) {
            return {leftNode, leftState};
        } else if (rightState == 2) {
            return {rightNode, rightState};
        } else if (leftState == 1 && rightState == 1) {
            return {root, 2};
        } else if (leftState == 1) {
            if (rootVal == pVal || rootVal == qVal) {
                return {root, 2};
            } else {
                return {leftNode, 1};
            }
        } else if (rightState == 1) {
            if (rootVal == pVal || rootVal == qVal) {
                return {root, 2};
            } else {
                return {rightNode, 1};
            }
        } else if (rootVal == pVal || rootVal == qVal){
            return {root, 1};
        } else {
            return {nullptr, 0};
        }

    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        auto [node, state] = dfs(root, p, q);
        if (state == 2) {
            return node;
        }

        return nullptr;
    }
};