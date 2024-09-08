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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> res;
        int num = 0;
        ListNode* curr = head;

        while (curr != nullptr) {
            num++;
            curr = curr->next;
        }

        int q = num/k, r = num%k;
        ListNode* node = head;
        for (int i=0; i<k; i++) {
            if (node == nullptr) {
                res.push_back(nullptr);
                continue;
            }

            ListNode* running = node;

            res.push_back(node);
            int cnt = 0;
            while (cnt != q + (r>0) - 1) {
                cnt++;
                running = running->next;
            }
            r--;

            node = running->next;
            running->next = nullptr;

        }

        return res;
    }
};