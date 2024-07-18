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
    int res = 0;
    unordered_map<int, int> dfs(TreeNode* node, int distance) {
        unordered_map<int, int> cnt;
        if (node == nullptr) return cnt;
        if (node->left == nullptr && node->right == nullptr) {
            cnt[0] = 1;
            return cnt;
        }

        unordered_map<int, int> leftMap = dfs(node->left, distance);
        unordered_map<int, int> rightMap = dfs(node->right, distance);

        for (auto &[k, v]:leftMap) {
            cnt[k+1] += v;
            for (auto &[k2, v2]:rightMap) {
                if (k + k2 + 2 <= distance) {
                    res += v*v2;
                }
            }
        }

        for (auto &[k, v]:rightMap) cnt[k+1] += v;

        return cnt;
    }
    int countPairs(TreeNode* root, int distance) {
        unordered_map<int, int> hmap = dfs(root, distance);
        return res;
    }
};