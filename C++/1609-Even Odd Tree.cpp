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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int depth = 0;
        while (!q.empty()) {
            int length = q.size();
            vector<int> arr;
            while (length > 0) {
                TreeNode* node = q.front();
                q.pop();
                if (!(depth%2)^((node->val)%2)){
                    return false;
                }
                arr.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
                length--;
            }

            if (!(depth%2)) {
                for (int i=1; i<arr.size(); i++) {
                    if (arr[i] <= arr[i-1]) return false;
                }
            } else {
                for (int i=1; i<arr.size(); i++) {
                    if (arr[i] >= arr[i-1]) return false;
                }                
            }
            depth++;
        }
        return true;
    }
};