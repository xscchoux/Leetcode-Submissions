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
class FindElements {
public:
    unordered_set<int> elements;
    void recover(TreeNode* node, int expected) {
        node->val = expected;
        elements.insert(expected);
        if (node->left != nullptr) {
            recover(node->left, 2*expected+1);
        }
        if (node->right != nullptr) {
            recover(node->right, 2*expected+2);
        }
    }
    FindElements(TreeNode* root) {
        recover(root, 0);
    }
    
    bool find(int target) {
        return elements.contains(target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */