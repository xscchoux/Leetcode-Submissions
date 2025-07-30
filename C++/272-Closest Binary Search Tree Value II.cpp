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
    void dfs(TreeNode* node, vector<int>& allNums) {
        if (node == nullptr) return;

        dfs(node->left, allNums);
        allNums.push_back(node->val);
        dfs(node->right, allNums);
    }
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        vector<int> nums;
        dfs(root, nums);
        double diff = DBL_MAX;

        int left = 0, right = k-1;
        for (int i=k-1; i<nums.size(); i++) {
            if (max(abs(target - nums[i-(k-1)]), abs(target - nums[i])) < diff) {
                right = i;
                left = i-(k-1);
                diff = max(abs(target - nums[left]), abs(target - nums[right]));
            }
        }

        return vector<int>(begin(nums) + left, begin(nums) + right+1);
    }
};



// Use deque, note the clever pruning
class Solution {
public:
    int k;
    double target;
    void dfs(TreeNode* node, deque<int>& dq) {
        if (node == nullptr) return;

        dfs(node->left, dq);
        dq.push_back(node->val);
        if (dq.size() > k) {
            if (abs(target - dq.front()) > abs(target - dq.back())) {
                dq.pop_front();
            } else {
                dq.pop_back();
                return;  // clever pruning
            }
        }
        dfs(node->right, dq);
    }
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        this->k = k;
        this->target = target;
        deque<int> dq;
        dfs(root, dq);

        return vector<int>(begin(dq), end(dq));
    }
};