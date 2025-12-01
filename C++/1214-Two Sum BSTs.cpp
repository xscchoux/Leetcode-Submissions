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
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        stack<TreeNode*> stk1, stk2;
        
        while (true){
            while (root1){
                stk1.push(root1);
                root1 = root1->left;
            }
            while (root2){
                stk2.push(root2);
                root2 = root2->right;
            }
            if (stk1.empty() || stk2.empty() ) return false;
            
            int currSum = stk1.top()->val + stk2.top()->val;

            if (currSum == target)
                return true;
            else if (currSum < target){
                root1 = stk1.top();
                stk1.pop();
                root1 = root1->right;               
            }
            else{
                root2 = stk2.top();
                stk2.pop();
                root2 = root2->left;                
            }
        }
    }
};


// Redo

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
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        stack<TreeNode*> st1, st2;
        while (root2 != nullptr) {
            st2.push(root2);
            root2 = root2->right;
        }

        while (true) {
            if (root1 != nullptr) {
                while (root1 != nullptr) {
                    st1.push(root1);
                    root1 = root1->left;
                }
            } else if (!st1.empty() && !st2.empty()) {
                root1 = st1.top();
                st1.pop();

                while (root1->val + st2.top()->val >= target) {
                    root2 = st2.top();
                    st2.pop();
                    if (root1->val + root2->val == target) return true;
                    else if (root2->left != nullptr) {
                        root2 = root2->left;
                        while (root2 != nullptr) {
                            st2.push(root2);
                            root2 = root2->right;
                        }
                    } else if (st2.empty()) {
                        break;
                    }
                }

                root1 = root1->right;
            } else {
                break;
            }
        }

        return false;
    }
};