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
    map<pair<TreeNode *, int>, int> memo;  // use map, but this requires O(logN) time to look up
    int cal(TreeNode* root, int state){
        if (!root) return 0;
        auto key = make_pair(root, state);
        if (memo.find(key) != memo.end()) return memo[key];
        
        int res;
        if (state == 0){
            res = 1 + cal(root->left, 1) + cal(root->right, 1);
            if (root->left) res = min(res, 1+cal(root->left, 2) + cal(root->right, 0) );
            if (root->right) res = min(res, 1+cal(root->right, 2) + cal(root->left, 0) );
        } else if (state == 1){
            res = min(1+cal(root->left, 1)+cal(root->right, 1), cal(root->left, 0)+cal(root->right, 0) );
        } else{
            res = cal(root->left, 1) + cal(root->right, 1);
        }
        memo[key] = res;
        return res;
    }
    
    int minCameraCover(TreeNode* root) {
        // define states, 0: not covered, 1: covered and not occupied, 2: covered and occupied
        return cal(root, 0);
    }
};