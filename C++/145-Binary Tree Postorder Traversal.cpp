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
    vector<int> res;
    void dfs(TreeNode* curr) {
        if (curr == nullptr) return;
        dfs(curr->left);
        dfs(curr->right);
        res.push_back(curr->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        dfs(root);
        return res;
    }
};




class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == nullptr) return res;
        stack<TreeNode*> stk;
        stk.push(root);
        
        while (!stk.empty()) {
            TreeNode* curr = stk.top();
            stk.pop();
            res.push_back(curr->val);

            if (curr->left != nullptr) {
                stk.push(curr->left);
            }
            if (curr->right != nullptr) {
                stk.push(curr->right);
            }
        }

        reverse(res.begin(), res.end());

        return res;
    }
};


// Very hard but clever iterative solution
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == nullptr) return res;
        stack<TreeNode*> stk;
        TreeNode* prevNode;

        while (true) {
            if (root != nullptr) {
                stk.push(root);
                root = root->left;
            } else if (!stk.empty()) {
                root = stk.top();
                if (root->right == nullptr || root->right == prevNode) {
                    stk.pop();
                    res.push_back(root->val);
                    prevNode = root;
                    root = nullptr; // we will traverse again and again from this node without this line
                    // Note that setting root to nullptr does not affect the prevNode. 
                    // prevNode still holds the reference to the node that root was pointing to before being set to nullptr.
                } else {
                    root = root->right;
                }
            } else {
                break;
            }
        }

        return res;
    }
};