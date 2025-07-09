/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// iterative inorder traversal
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        stack<TreeNode*> stk;
        TreeNode* prev = nullptr;
        while (true) {
            if (root != nullptr) {
                stk.push(root);
                root = root->left;
            } else if (!stk.empty()) {
                TreeNode* node = stk.top();
                stk.pop();
                if (prev == p) {
                    return node;
                }
                prev = node;
                root = node->right;
            } else {
                break;
            }
        }
        return nullptr;
    }
};


// Beautiful but hard to come up with
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* successor = nullptr;

        while (root != nullptr) {
            if (root->val <= p->val) {  // ignore left tree, and find the node with value greater than p
                root = root->right;
            } else {  // root->val > p->val, so check left tree
                successor = root;   // candidate successor
                root = root->left;
            }
        }

        return successor;
    }
};