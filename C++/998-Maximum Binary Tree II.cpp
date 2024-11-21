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

// First try
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
    vector<int> getVector(TreeNode* node) {
        if (node == nullptr) return vector<int>();
        vector<int> leftArr = getVector(node->left);
        vector<int> rightArr = getVector(node->right);

        leftArr.push_back(node->val);
        leftArr.insert(leftArr.end(), rightArr.begin(), rightArr.end());
        return leftArr;
    }

    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        auto vec = getVector(root);
        vec.push_back(val);
        return create(vec, 0, vec.size()-1);
    }
};



// O(n) solution, check right children only, hard to come up with
class Solution {
public:
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        TreeNode* parent = new TreeNode(INT_MAX);
        parent->right = root;

        TreeNode* running = parent;

        while (true) {
            if (running->right != nullptr && running->right->val < val) {
                TreeNode* tmp = running->right;
                running->right = new TreeNode(val);
                running->right->left = tmp;
                break;
            } else if (running->right == nullptr) {
                running->right = new TreeNode(val);
                break;
            }
            running = running->right;
        }

        return parent->right;
    }
};