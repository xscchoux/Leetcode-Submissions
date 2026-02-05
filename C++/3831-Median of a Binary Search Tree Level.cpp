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
    void dfs(TreeNode* node, int level, int currLevel, vector<int>& arr) {
        
        if (currLevel == level) {
            arr.push_back(node->val);
        }
        if (currLevel < level) {
            if (node->left != nullptr) {
                dfs(node->left, level, currLevel+1, arr);
            }
            if (node->right != nullptr) {
                dfs(node->right, level, currLevel+1, arr);
            }
        }

    }
    int levelMedian(TreeNode* root, int level) {
        vector<int> arr;
        dfs(root, level, 0, arr);
        
        if (arr.empty()) {
            return -1;
        }

        int N = arr.size();
        // sort(begin(arr), end(arr));  // No need to sort arr since this is a BST
        return arr[N/2];
    }
};


