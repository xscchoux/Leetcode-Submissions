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
using LL = long long;
class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        queue<TreeNode*> q;
        q.push(root);
        vector<LL> arr;
        while (!q.empty()) {
            int size = q.size();
            LL tot = 0;
            while (size-- > 0) {
                TreeNode* curr = q.front();
                q.pop();
                tot += curr->val;
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
            arr.push_back(tot);
        }
        sort(begin(arr), end(arr), greater<>());

        return (arr.size() < k)?-1:arr[k-1];
    }
};