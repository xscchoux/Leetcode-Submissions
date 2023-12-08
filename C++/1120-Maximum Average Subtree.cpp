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
    double mx = 0;
    pair<int, int> dfs(TreeNode* node) {
        if (node == nullptr) return {0, 0};
        int curr = node->val;
        auto [lCount, lTot] = dfs(node->left);
        auto [rCount, rTot] = dfs(node->right);
        mx = max(mx, (double)(curr+lTot+rTot)/(lCount+rCount+1));
        return {lCount+rCount+1, (curr+lTot+rTot) };
    }
    double maximumAverageSubtree(TreeNode* root) {
        dfs(root);
        return mx;
    }
};


// solution 2

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
    double maximumAverageSubtree(TreeNode* root) {
        State res = dfs(root);
        
        return res.avg;
    }
private:
    struct State {
        int count;
        int tot;
        double avg;
    };
    State dfs(TreeNode* node) {
        if (node == nullptr) return {0, 0, 0};
        State left = dfs(node->left);
        State right = dfs(node->right);
        int nodeCount = left.count + right.count + 1;
        int nodeSum = left.tot + right.tot + node->val;
        double avg = max((1.0)*nodeSum/nodeCount, max(left.avg, right.avg));
        return {nodeCount, nodeSum, avg};
    }
};