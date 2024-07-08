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
    ListNode* deleteDuplicatesUnsorted(ListNode* head) {
        unordered_map<int, int> cnt;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* temp = head;

        while (temp) {
            cnt[temp->val]++;
            temp = temp->next;
        }

        ListNode* running = dummy;
        while (running) {
            if (running->next != nullptr && cnt[running->next->val] > 1) {
                running->next = running->next->next;
            } else {
                running = running->next;
            }
        }

        return dummy->next;
    }
};