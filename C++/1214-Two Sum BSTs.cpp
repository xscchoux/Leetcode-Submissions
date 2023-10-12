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