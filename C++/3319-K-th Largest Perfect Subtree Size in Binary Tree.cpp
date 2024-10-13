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
    vector<int> arr;
    int dfs(TreeNode* node) {
        if (node == nullptr) return 0;
        int l = dfs(node->left);
        int r = dfs(node->right);
        if (l == r) {
            arr.push_back(l+r+1);
            return l+r+1;
        }
        return -1;
    }
    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        dfs(root);
        sort(begin(arr), end(arr), greater<>());
        if (k > arr.size()) return -1;
        return arr[k-1];
    }
};