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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int preVal = -1;
        int prevCritIdx = -1, idx = 0;
        int firstCritIdx = -1;
        int mx = INT_MIN, mn = INT_MAX;
        
        while (head->next != nullptr) {
            int curr = head->val;
            if (idx > 0) {
                if ((preVal < curr && curr > head->next->val) || (preVal > curr && curr < head->next->val)) {
                    if (prevCritIdx > -1) mn = min(mn, idx-prevCritIdx);
                    prevCritIdx = idx;
                    if (firstCritIdx == -1) firstCritIdx = idx;
                    mx = idx - firstCritIdx;
                }
            }
            preVal = head->val;
            head = head->next;
            idx++;
        }

        return {(mn < INT_MAX)?mn:-1, (mn < INT_MAX)?mx:-1};
    }
};