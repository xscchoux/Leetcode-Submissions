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
    string gameResult(ListNode* head) {
        int point = 0;
        while (head) {
            int p1 = head->val;
            head = head->next;
            int p2 = head->val;
            head = head->next;
            point += p1>p2?1:p1==p2?0:-1;
        }
        
        return point>0?"Even":(point==0)?"Tie":"Odd";
    }
};