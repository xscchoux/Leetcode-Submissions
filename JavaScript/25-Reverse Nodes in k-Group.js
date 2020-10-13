/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} k
 * @return {ListNode}
 */
var reverseKGroup = function(head, k) {
    if (!head) return null;
    
    let curr = head;
    
    for (let i=0; i<k-1; i++){
        curr = curr.next;
        if (curr===null){
            return head;
        }
    }
    
    let prev = reverseKGroup(curr.next, k);
    
    for (let i=0; i<k; i++){
        let tmp = head.next;
        head.next = prev;
        prev = head;
        head = tmp;
    }
    return prev;
};