/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} n
 * @return {ListNode}
 */
var removeNthFromEnd = function(head, n) {
    let first = head, second = head;
    for (let i=0; i<n; i++){
        first = first.next;
    }
    
    if (!first) return head.next;
    
    while (first.next){
        first = first.next;
        second = second.next;
    }
    
    second.next = second.next.next;
    
    return head;
    
};