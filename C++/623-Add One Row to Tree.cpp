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
    int val;
    int depth;
    void dfs(TreeNode* node, int d) {
        if (node == nullptr) return;
        if (d == depth-1) {
            TreeNode* leftNxt = node->left;
            TreeNode* rightNxt = node->right;
            node->left = new TreeNode(val);
            node->left->left = leftNxt;
            node->right = new TreeNode(val);
            node->right->right = rightNxt;
            dfs(leftNxt, d+2);
            dfs(rightNxt, d+2);                  
        } else {
            dfs(node->left, d+1);
            dfs(node->right, d+1);   
        }
    }
    
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        this->val = val;
        this->depth = depth;
        if (depth == 1) {
            TreeNode* head = new TreeNode(val);
            head->left = root;
            return head;
        }
        dfs(root, 1);
        return root;
    }
};






// BFS
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) return new TreeNode(val, root, nullptr);
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            int len = q.size();
            while (len > 0) {
                TreeNode* node = q.front();
                q.pop();
                if (depth == 2) {
                    node->left = new TreeNode(val, node->left, nullptr);
                    node->right = new TreeNode(val, nullptr, node->right);
                } else {
                    if (node->left != nullptr) q.push(node->left);
                    if (node->right != nullptr) q.push(node->right);
                }
                len--;
            }
            depth--;
        }
        
        return root;
    }
};