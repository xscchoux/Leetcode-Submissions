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
var rotateRight = function(head, k) {
    if (!head || k === 0) return head;
    
    let count = 1;
    let tmp = head;
    while (tmp.next){
        count += 1;
        tmp = tmp.next;
    }
    tmp.next = head;
    
    for (let i=0; i<(count-k%count); i++){
        tmp = tmp.next;
    }
    
    let newHead = tmp.next;
    tmp.next = null;
    
    return newHead;
};