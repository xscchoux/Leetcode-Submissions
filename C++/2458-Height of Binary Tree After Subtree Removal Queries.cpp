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

// first try, use two maps, not efficient
class Solution {
public:
    unordered_map<int, pair<int, int>> nodeInfo; // root value:{level, height}
    unordered_map<int, multiset<int, greater<int>>> levelVals; // level: height values
    int dfs(TreeNode* node, int lvl) {
        if (node == nullptr) return 0;
        int height = 1 + max(dfs(node->left, lvl+1), dfs(node->right, lvl+1));
        nodeInfo[node->val] = {lvl, height-1};
        levelVals[lvl].insert(height-1);
        return height;
    }
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        dfs(root, 0);
        vector<int> res;
        int maxHeight = nodeInfo[root->val].second;
        for (int q:queries) {
            auto &[lvl, currHeight] = nodeInfo[q];
            if (levelVals[lvl].size() <= 1) {
                res.push_back(lvl-1);
            } else if ( *levelVals[lvl].begin() > currHeight ) {
                res.push_back(*levelVals[lvl].begin() + lvl);
            } else {
                auto it = levelVals[lvl].begin();
                advance(it, 1);
                res.push_back(*it + lvl);
            }
        }
        return res;
    }
};




// clever preorder traversal
class Solution {
public:
    unordered_map<int, int> height;
    int currMax = 0;
    void dfsLeftRight(TreeNode* node, int curr) {  // preorder, left paths first
        if (node == nullptr) return;

        // Store the maximum height if this node were removed
        height[node->val] = currMax;

        currMax = max(currMax, curr);

        dfsLeftRight(node->left, curr+1);
        dfsLeftRight(node->right, curr+1);
    }
    void dfsRightLeft(TreeNode* node, int curr) {  // preorder, right paths first
        if (node == nullptr) return;

        // Store the maximum height if this node were removed
        height[node->val] = max(height[node->val], currMax);

        currMax = max(currMax, curr);

        dfsRightLeft(node->right, curr+1);
        dfsRightLeft(node->left, curr+1);
    }
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        dfsLeftRight(root, 0);
        currMax = 0;
        dfsRightLeft(root, 0);        

        vector<int> res;
        for (int q:queries) {
            res.push_back(height[q]);
        }

        return res;
    }
};