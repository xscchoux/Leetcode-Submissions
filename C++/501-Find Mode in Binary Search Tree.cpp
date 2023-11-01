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
    vector<int> res;
    int mx = 0;
    TreeNode* pre = nullptr;
    int count = 0;
    void dfs(TreeNode* node){
        if (node == nullptr) return;
        dfs(node->left);
        if (pre != nullptr && pre->val == node->val){
            count++;
        } else{
            count = 1;
        }
        if (count > mx){
            mx = count;
            res.clear();
            res.push_back(node->val);
        } else if (count == mx){
            res.push_back(node->val);
        }
        pre = node;

        dfs(node->right);
    }
    
public:
    vector<int> findMode(TreeNode* root) {
        dfs(root);
        return res;
    }
};