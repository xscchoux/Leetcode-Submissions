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
    int tot;
    int calTot(TreeNode* node) {
        if (node == nullptr) return 0;
        int res = node->val;
        res += calTot(node->left);
        res += calTot(node->right);
        
        return res;
    }

    pair<int, int> check(TreeNode* node) {
        if (node == nullptr) return {0, false};
        int curr = node->val;
        auto [leftSum, isLeftHalf] = check(node->left);
        auto [rightSum, isRightHalf] = check(node->right);

        int currHalf = 0;
        if (isLeftHalf || isRightHalf || (node->left != nullptr && leftSum == tot/2) || (node->right != nullptr && rightSum == tot/2) ) {   // Use (node->left != nullptr && leftSum == tot/2) because there may be no left node and total sum is 0
            currHalf = 1;
        }

        return {curr+leftSum+rightSum, currHalf};
    }

    bool checkEqualTree(TreeNode* root) {
        this->tot = calTot(root);
        if (tot%2) return false;

        auto [tot, res] = check(root);

        return res==1?true:false;
    }
};