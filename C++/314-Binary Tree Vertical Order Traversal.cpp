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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }
        map<int, vector<int>> hmap;
        deque<pair<TreeNode*, int>> dq;

        dq.push_back({root, 0});

        while (!dq.empty()) {
            int sz = dq.size();
            while (sz-- > 0) {
                auto [node, idx] = dq.front();
                dq.pop_front();
                hmap[idx].push_back(node->val);
                if (node->left != nullptr) {
                    dq.push_back({node->left, idx-1});
                }
                if (node->right != nullptr) {
                    dq.push_back({node->right, idx+1});
                }
            }
        }

        vector<vector<int>> res;
        for (auto &[_, v]:hmap) {
            res.push_back(v);
        }

        return res;
    }
};