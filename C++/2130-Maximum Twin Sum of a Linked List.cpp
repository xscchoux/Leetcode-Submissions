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


// O(N) time and O(1) space
class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode* slow = head, * fast = head;

        // find middle node
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode* prev = nullptr;
        while (slow) {
            ListNode* nxt = slow->next;
            slow->next = prev;
            prev = slow;
            slow = nxt;
        }

        int res = INT_MIN;
        ListNode *start = prev;
        while (prev) {
            res = max(res, prev->val + head->val);
            prev = prev->next;
            head = head->next;
        }

        return res;
    }
};