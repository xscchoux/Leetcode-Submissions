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
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        
        // find the head of the second half
        while (fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // reverse the second half
        ListNode* reversed = nullptr;
        while (slow != nullptr) {
            ListNode* tmp = slow->next;
            slow->next = reversed;
            reversed = slow;
            slow = tmp;
        }
        
        // compare first half and second half
        while (reversed != nullptr) {
            if (reversed->val != head->val) {
                return false;
            }
            head = head->next;
            reversed = reversed->next;
        }
        
        return true;
    }
};