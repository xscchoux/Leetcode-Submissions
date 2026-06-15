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
    ListNode* deleteMiddle(ListNode* head) {
        if (head->next == nullptr) {  // edge case
            return nullptr;
        }

        ListNode* prev = new ListNode(-1);
        prev->next = head;

        ListNode* slow = head, * fast = head;
        
        // middle node: slow node
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            prev = prev->next;
        }

        prev->next = slow->next;

        return head;
    }
};