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
    ListNode* frequenciesOfElements(ListNode* head) {
        ListNode* tmp = head;
        unordered_map<int, int> hmap;
        
        while (tmp) {
            hmap[tmp->val]++;
            tmp = tmp->next;
        }
        
        ListNode* newHead = new ListNode();
        ListNode* prev = newHead;
        
        for (auto [_, v]:hmap) {
            newHead->next = new ListNode(v);
            newHead = newHead->next;
        }
        
        return prev->next;
    }
};