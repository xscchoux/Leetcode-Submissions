/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool traversal(ListNode* listHead, TreeNode* curr) {
        if (listHead->next == nullptr) return true;
        if (curr->left == nullptr && curr->right == nullptr) return false;
        
        bool res = false;
        
        if (curr->left != nullptr && listHead->next != nullptr && curr->left->val == listHead->next->val) {
            res |= traversal(listHead->next, curr->left);
        }
        if (curr->right != nullptr && listHead->next != nullptr && curr->right->val == listHead->next->val) {
            res |= traversal(listHead->next, curr->right);
        }

        return res;
    }
    bool dfs(ListNode* listHead, TreeNode* curr) {
        if (curr == nullptr) return false;
        if (curr->val == listHead->val && traversal(listHead, curr)) {
            return true;
        }
        return (dfs(listHead, curr->left) || dfs(listHead, curr->right));
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        return dfs(head, root);
    }
};