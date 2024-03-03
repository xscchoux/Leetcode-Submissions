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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int cnt = 0;
        ListNode* tmp = head;
        while (tmp) {
            cnt++;
            tmp = tmp->next;
        }
        
        int ind = cnt-n;
        ListNode* prev = new ListNode(-1);
        prev->next = head;
        
        int nextIdx = 0;
        ListNode* running = prev;
        while (running) {
            if (nextIdx == ind) {
                running->next = running->next->next;
            }
            running = running->next;
            nextIdx++;
        }
        
        return prev->next;
    }
};