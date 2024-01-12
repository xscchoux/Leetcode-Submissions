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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        stack<TreeNode*> s1, s2;
        vector<int> res1, res2;
        
        while (true){
            if (root1 || root2) {
                if (root1){
                    s1.push(root1);
                    root1 = root1->left;       
                }
                if (root2){
                    s2.push(root2);
                    root2 = root2->left;       
                }
            } else if (!s1.empty() || !s2.empty()) {
                if (!s1.empty()){
                    root1 = s1.top();
                    if (!(root1->left || root1->right)) res1.push_back(root1->val);
                    s1.pop();
                    root1 = root1->right;                    
                }
                if (!s2.empty()){
                    root2 = s2.top();
                    if (!(root2->left || root2->right)) res2.push_back(root2->val);
                    s2.pop();
                    root2 = root2->right;                    
                }
            } else {
                break;
            }
        }
        return res1==res2;
    }
};