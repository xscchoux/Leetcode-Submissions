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
    vector<int> hmap = vector<int>(9, 0);
    // The reason for this is that the parentheses in hmap(9, 0) could be interpreted as a function declaration, not a variable initialization
    // C++ only allows the assignment syntax for member variable initialization in the class definition
    // This is vexing parse. Better to declare hmap in a constructor
    void count(TreeNode* node) {
        int v = node->val;
        if (!node->left && !node->right) {
            hmap[v-1]++;
            int odd = 0;
            for (int i=0; i<9; i++) {
                if (hmap[i]%2 != 0) odd++;
            }
            hmap[v-1]--;
            if (odd == 0 || odd == 1) res++;;
        }
        hmap[v-1]++;
        if (node->left) count(node->left);
        if (node->right) count(node->right);
        hmap[v-1]--;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        count(root);
        return res;
    }
};