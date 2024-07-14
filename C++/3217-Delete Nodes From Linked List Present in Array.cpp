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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> s(nums.begin(), nums.end());
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* running = dummy;

        while (head != nullptr) {
            if (!s.contains(head->val)) {
                running->next = new ListNode(head->val);
                running = running->next;
            }
            head = head->next;
        }

        return dummy->next;
    }
};


// better
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ListNode* temp = new ListNode(-1, head);
        unordered_set<int> s(nums.begin(), nums.end());

        for (ListNode* cur = temp; cur->next != nullptr;) {
            if (s.contains(cur->next->val)) {
                cur->next = cur->next->next;
            } else {
                cur = cur->next;
            }
        }

        return temp->next;
    }
};