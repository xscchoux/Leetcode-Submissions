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
    TreeNode* create(vector<int>& nums, int left, int right) {
        if (left > right) return nullptr;
        if (left == right) return new TreeNode(nums[left]);
        int maxIdx = max_element(nums.begin()+left, nums.begin()+right+1) - nums.begin();
        TreeNode* curr = new TreeNode(nums[maxIdx]);
        curr->left = create(nums, left, maxIdx-1);
        curr->right = create(nums, maxIdx+1, right);

        return curr;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {      
        return create(nums, 0, nums.size()-1);
    }
};