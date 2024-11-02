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

// break down into several cases, much easier
class Solution {
public:
    int res = INT_MIN;
    tuple<int, int, int> dfs(TreeNode* node) {  // subtree max, subtree min, subtree sum
        if (node->left == nullptr && node->right == nullptr) {
            res = max(res, node->val);
            return {node->val, node->val, node->val};
        }

        if (node->left == nullptr) {
            auto [mx, mn, rightSum] = dfs(node->right);
            if (node->val < mn) {
                res = max(res, node->val + rightSum);
                return {mx, node->val, rightSum+node->val};
            }
            return {INT_MAX, INT_MIN, -1};
        }

        if (node->right == nullptr) {
            auto [mx, mn, leftSum] = dfs(node->left);
            if (node->val > mx) {
                res = max(res, node->val + leftSum);
                return {node->val, mn, leftSum+node->val};
            }
            return {INT_MAX, INT_MIN, -1};
        }

        auto [leftMax, leftMin, leftSum] = dfs(node->left);
        auto [rightMax, rightMin, rightSum] = dfs(node->right);

        if (node->val > leftMax && node->val < rightMin) {
            res = max(res, node->val + leftSum + rightSum);
            return {rightMax, leftMin, node->val+leftSum+rightSum};
        }

        return {INT_MAX, INT_MIN, -1};
    }
    int maxSumBST(TreeNode* root) {
        dfs(root);

        return (res<0)?0:res;
    }
};


// Hard to come up with (note the values when node == nullptr)
class Solution {
public:
    int ans = 0;
    tuple<int, int, bool, int> dfs(TreeNode* node) {
        if (node == nullptr) {
            return {INT_MIN, INT_MAX, true, 0};   // {max value, min value, isBST, sum}
        }

        auto [leftMax, leftMin, leftIsBST, leftSum] = dfs(node->left);
        auto [rightMax, rightMin, rightIsBST, rightSum] = dfs(node->right);

        int value = node->val, sum = value + leftSum + rightSum;
        bool isBST = false;
        if (value > leftMax && value < rightMin && leftIsBST && rightIsBST) {
            ans = max(ans, sum);
            isBST = true;
        }

        return { max(node->val, rightMax), min(node->val, leftMin), isBST, sum};  // this is tricky. We need min and max when child nodes are nullptrs
    }
    int maxSumBST(TreeNode* root) {
        dfs(root);
        return ans;
    }
};


// More concise, without using isBST
class Solution {
public:
    int res = INT_MIN;
    tuple<int, int, int> dfs(TreeNode* node) {  // {max value, min value, sum}
        if (node == nullptr) {
            return {INT_MIN, INT_MAX, 0};
        }

        auto [leftMax, leftMin, leftSum] = dfs(node->left);
        auto [rightMax, rightMin, rightSum] = dfs(node->right);

        if (node->val > leftMax && node->val < rightMin) {
            res = max(res, leftSum + node->val + rightSum);
            return {max(rightMax, node->val), min(leftMin, node->val), leftSum + node->val + rightSum};  // // this is tricky. We need min and max when child nodes are nullptrs
        }

        return {INT_MAX, INT_MIN, -1};
    }
    int maxSumBST(TreeNode* root) {
        dfs(root);
        return (res<0)?0:res;
    }
};



// Much faster than the solution using tuple (Maybe copying or constructing the tuple incurs overhead)
struct Node {
    int mx;
    int mn;
    int sum;
};
class Solution {
public:
    int res = 0;
    Node* dfs(TreeNode* node) {  // {max value, min value, sum}
        if (node == nullptr) {
            return new Node(INT_MIN, INT_MAX, 0);
        }

        Node* leftNode = dfs(node->left);
        Node* rightNode = dfs(node->right);

        if (node->val > leftNode->mx && node->val < rightNode->mn) {
            res = max(res, leftNode->sum + node->val + rightNode->sum);
            return new Node(max(rightNode->mx, node->val), min(leftNode->mn, node->val), leftNode->sum + node->val + rightNode->sum);
        }

        return new Node(INT_MAX, INT_MIN, -1);
    }
    int maxSumBST(TreeNode* root) {
        dfs(root);
        return res;
    }
};