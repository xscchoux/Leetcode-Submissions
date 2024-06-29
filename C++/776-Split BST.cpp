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

// My solution
class Solution {
public:
    TreeNode* deepCopy(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        }

        TreeNode* newRoot = new TreeNode(root->val);
        newRoot->left = deepCopy(root->left);
        newRoot->right = deepCopy(root->right);
        
        return newRoot;
    }
    TreeNode* getMore(TreeNode* node, int target) {
        if (node == nullptr) return node;

        while (node != nullptr && node->val <= target) node = node->right;
        if (node == nullptr) return node;
        node->left = getMore(node->left, target);
        return node;
    }
    TreeNode* getLess(TreeNode* node, int target) {
        if (node == nullptr) return node;

        while (node != nullptr && node->val > target) node = node->left;
        if (node == nullptr) return node;
        node->right = getLess(node->right, target);
        return node;
    }
    vector<TreeNode*> splitBST(TreeNode* root, int target) {
        
        vector<TreeNode*> res;
        TreeNode* rootCopy = deepCopy(root);
        res.push_back(getLess(root, target));
        res.push_back(getMore(rootCopy, target));
        
        return res;
    }
};




// Beautiful recursive one
class Solution {
public:
    vector<TreeNode*> splitBST(TreeNode* root, int target) {
        if (root == nullptr) return {nullptr, nullptr};
        
        int v = root->val;
        
        if (v > target) {
            auto leftArr = splitBST(root->left, target);
            root->left = leftArr[1];
            return {leftArr[0], root};
        } else {
            auto rightArr = splitBST(root->right, target);
            root->right = rightArr[0];
            return {root, rightArr[1]};
        }

    }
};