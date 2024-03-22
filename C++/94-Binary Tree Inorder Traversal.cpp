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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stk;
        while (true){
            if (root != nullptr){
                stk.push(root);
                root = root->left;
            }else if (!stk.empty()){
                root = stk.top();
                stk.pop();
                res.push_back(root->val);
                root = root->right;
            } else{
                break;
            }
        }
        return res;
    }
};


// Morris traversal
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        while (root != nullptr){
            if (root->left == nullptr){
                res.push_back(root->val);
                root = root->right;
            } else {
                TreeNode* predecessor = root->left;
                while (predecessor->right != nullptr && predecessor->right != root){
                    predecessor = predecessor->right;
                }
                if (predecessor->right == nullptr){
                    predecessor->right = root;
                    root = root->left;
                } else {
                    predecessor->right = nullptr;
                    res.push_back(root->val);
                    root = root->right;
                }
            }
        }
        return res;
    }
};