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
    vector<long long> zigzagLevelSum(TreeNode* root) {
        deque<TreeNode*> q;
        q.push_back(root);
        int level = 1;
        vector<long long> res;
        
        while (!q.empty()) {
            int sz = q.size();
            bool stop = false;
            long long tot = 0;
            while (sz-- > 0) {
                if (level%2) {
                    TreeNode* curr = q.front();
                    q.pop_front();
                    if (!stop && curr->left == nullptr) {
                        stop = true;
                    }
                    if (!stop) {
                        tot += curr->val;
                    }
                    if (curr->left != nullptr) {
                        q.push_back(curr->left);
                    }
                    if (curr->right != nullptr) {
                        q.push_back(curr->right);
                    }
                } else {
                    TreeNode* curr = q.back();
                    q.pop_back();
                    if (!stop && curr->right == nullptr) {
                        stop = true;
                    }
                    if (!stop) {
                        tot += curr->val;
                    }
                    if (curr->right != nullptr) {
                        q.push_front(curr->right);
                    }
                    if (curr->left != nullptr) {
                        q.push_front(curr->left);
                    }
                }
            }
            res.push_back(tot);
            level ^= 1;
        }

        return res;
    }
};