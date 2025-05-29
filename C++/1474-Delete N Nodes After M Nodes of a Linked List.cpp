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

// First AC
class Solution {
public:
    ListNode* deleteNodes(ListNode* head, int m, int n) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* running = dummy;

        while (true) {
            int step = m;
            while (step > 0 && running != nullptr) {
                running = running->next;
                step--;
            }
            if (running == nullptr) break;
            
            ListNode* nxt = running;
            int skip = n;
            while (skip > 0 && nxt != nullptr) {
                nxt = nxt->next;
                skip--;
            }
            if (nxt != nullptr && nxt->next != nullptr) {
                running->next = nxt->next;
            } else {
                running->next = nullptr;
                break;
            }
        }
        return dummy->next;
    }
};



// Better
class Solution {
public:
    ListNode* deleteNodes(ListNode* head, int m, int n) {
        ListNode* currNode = head;
        ListNode* lastNode = head;
        while (currNode != nullptr) {
            int step = m, skip = n;
            while (step > 0 && currNode != nullptr) {
                lastNode = currNode;
                currNode = currNode->next;
                step--;
            }
            while (skip > 0 && currNode != nullptr) {
                currNode = currNode->next;
                skip--;
            }
            lastNode->next = currNode;
        }

        return head;
    }
};