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
    vector<int> largestValues(TreeNode* root) {
        if (root == nullptr) return {};
        vector<int> res;
        deque<TreeNode*> queue;
        queue.push_front(root);
        
        while (!queue.empty()){
            int length = queue.size();
            int mx = INT_MIN;
            for (int i=0; i<length; i++){
                TreeNode* curr = queue.back();
                queue.pop_back();
                if (curr->val > mx) mx = curr->val;
                if (curr->left) queue.push_front(curr->left);
                if (curr->right) queue.push_front(curr->right);
            }
            res.push_back(mx);
        }
        return res;
    }
};