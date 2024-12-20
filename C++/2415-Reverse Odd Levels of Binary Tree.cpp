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
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int depth = 0;
        vector<TreeNode*> children;  // declare outside the while loop to avoid repeated memory allocation and deallocation during each iteration

        while (!q.empty()) {
            int length = q.size();
            while (length-- > 0) {
                TreeNode* curr = q.front();
                if (depth%2) children.push_back(curr);
                q.pop();
                if (curr->left != nullptr) q.push(curr->left);
                if (curr->right != nullptr) q.push(curr->right);                
            }
            int left = 0, right = children.size()-1;
            while (left < right) {
                swap(children[left]->val, children[right]->val);
                left++; right--;
            }
            children.clear();
            depth++;
        }

        return root;
    }
};