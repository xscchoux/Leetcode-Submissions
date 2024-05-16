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
    bool evaluateTree(TreeNode* root) {
        int value = root->val;
        if (value == 0) return false;
        else if (value == 1) return true;
        else if (value == 2) {
            return evaluateTree(root->left) || evaluateTree(root->right);
        } else {
            return evaluateTree(root->left) && evaluateTree(root->right);
        }
    }
};


// Iterative
class Solution {
public:
    bool evaluateTree(TreeNode* root) {
        stack<TreeNode*> stk;
        stk.push(root);
        unordered_map<TreeNode*, bool> hmap;

        while (!stk.empty()) {
            TreeNode* curr = stk.top();
            if (!curr->left && !curr->right) {
                stk.pop();
                hmap[curr] = curr->val;
                continue;
            }

            if (hmap.find(curr->left) != hmap.end() && hmap.find(curr->right) != hmap.end()) {
                stk.pop();
                if (curr->val == 2) {
                    hmap[curr] = hmap[curr->left] || hmap[curr->right];
                } else {
                    hmap[curr] = hmap[curr->left] && hmap[curr->right];
                }
            } else {
                stk.push(curr->right);
                stk.push(curr->left);
            }
        }
        return hmap[root];
    }
};