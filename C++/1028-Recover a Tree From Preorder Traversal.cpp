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

// first AC (using map to store the parent node)
class Solution {
public:
    TreeNode* recoverFromPreorder(string traversal) {
        unordered_map<TreeNode*, TreeNode*> parent;
        int preDash = 0, currDash = 0, N = traversal.size();
        int idx = 0;
        TreeNode* currNode = new TreeNode(-1);
        TreeNode* root = currNode;
        string nxt = "l";

        while (idx < N) {
            if (isdigit(traversal[idx])) {
                int num = 0;
                while (idx < N && isdigit(traversal[idx])) {
                    num = num*10 + (traversal[idx]-'0');
                    idx++;
                }
                TreeNode* newNode = new TreeNode(num);
                if (nxt == "l") {
                    currNode->left = newNode;
                } else {
                    currNode->right = newNode;
                }
                parent[newNode] = currNode;
                currNode = newNode;
            } else {
                int currDash = 0;
                while (idx<N && traversal[idx] == '-') {
                    currDash++;
                    idx++;
                }
                if (currDash == preDash + 1) {
                    nxt = "l";
                } else {
                    int diff = preDash - currDash+1;
                    while (diff--) {
                        currNode = parent[currNode];
                    }
                    nxt = "r";
                }
                preDash = currDash;
            }
        }
        return root->left;
    }
};




// Better, stack
class Solution {
public:
    TreeNode* recoverFromPreorder(string traversal) {
        stack<TreeNode*> stk;
        int N = traversal.size(), idx = 0;
        string nxt = "l";

        while (idx < N) {
            if (isdigit(traversal[idx])) {
                int num = 0;
                while (idx < N && isdigit(traversal[idx])) {
                    num = num*10 + (traversal[idx]-'0');
                    idx++;
                }
                TreeNode* newNode = new TreeNode(num);

                if (!stk.empty()) {
                    if (stk.top()->left == nullptr) stk.top()->left = newNode;
                    else stk.top()->right = newNode;
                }
                stk.push(newNode);
            } else {
                int currDash = 0;
                while (idx<N && traversal[idx] == '-') {
                    currDash++;
                    idx++;
                }
                while (stk.size() > currDash) {
                    stk.pop();
                } 
            }
        }
        while (stk.size() > 1) {
            stk.pop();
        }
        return stk.top();
    }
};