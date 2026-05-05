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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr) return head;
        ListNode* tmp = head;
        int N = 0;
        while (tmp != nullptr) {
            N++;
            tmp = tmp->next;
        }
        k = k%N;
        if (k == 0) return head;

        tmp = head;
        ListNode* newRoot;
        ListNode* prev = new ListNode(-1);
        prev->next = head;
        int cnt = 0;
        while (cnt < N-k) {
            cnt++;
            prev = prev->next;
            tmp = tmp->next;
        }
        newRoot = tmp;

        prev->next = nullptr;

        ListNode* newRunning = newRoot;
        while (newRunning->next != nullptr) {
            newRunning = newRunning->next;
        }

        newRunning->next = head;


        return newRoot;
    }
};