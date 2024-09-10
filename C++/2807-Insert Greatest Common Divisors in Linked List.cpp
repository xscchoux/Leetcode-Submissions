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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        while (head != nullptr) {
            if (head->next != nullptr) {
                int GCD = __gcd(head->val, head->next->val);
                ListNode* nxt = new ListNode(GCD);
                nxt->next = head->next;
                head->next = nxt;
                head = nxt->next;
            } else {
                head = head->next;
            }
        }

        return dummy->next;
    }
};