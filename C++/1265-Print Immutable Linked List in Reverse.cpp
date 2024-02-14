/**
 * // This is the ImmutableListNode's API interface.
 * // You should not implement it, or speculate about its implementation.
 * class ImmutableListNode {
 * public:
 *    void printValue(); // print the value of the node.
 *    ImmutableListNode* getNext(); // return the next node.
 * };
 */

class Solution {
public:
    void dfs(ImmutableListNode* head) {
        if (head->getNext()!=nullptr) dfs(head->getNext());
        head->printValue();
    }
    
    void printLinkedListInReverse(ImmutableListNode* head) {
        dfs(head);
    }
};