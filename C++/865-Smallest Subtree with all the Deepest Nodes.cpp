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

// First AC
class Solution {
public:
    int mxDepth = 0;
    TreeNode* res;
    int maxDepth(TreeNode* node) {
        if (node == nullptr) return 0;
        return 1 + max(maxDepth(node->left), maxDepth(node->right));
    }
    bool dfs(TreeNode* node, int depth) {
        if (node == nullptr) return false;

        if (depth == mxDepth) {
            res = node;
            return true;
        }

        bool leftBool = dfs(node->left, depth+1);
        bool rightBool = dfs(node->right, depth+1);

        if (leftBool && rightBool) res = node;

        return leftBool|rightBool;
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        mxDepth = maxDepth(root);

        dfs(root, 1);

        return res;
    }
};




// one recursion, really clever!!
class Solution {
private:
    struct NodeInfo {
        TreeNode* node = nullptr;
        int dist = 0;
        NodeInfo(TreeNode* n, int d): node(n), dist(d) {
        }
    };
    NodeInfo dfs(TreeNode* node) {
        if (node == nullptr) {
            return NodeInfo(nullptr, 0);
        }
        NodeInfo L = dfs(node->left), R = dfs(node->right);
        if (L.dist > R.dist) {
            return NodeInfo(L.node, L.dist+1);
        }
        if (R.dist > L.dist) {
            return NodeInfo(R.node, R.dist+1);
        }
        return NodeInfo(node, L.dist+1);
    }
public:

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return dfs(root).node;
    }
};