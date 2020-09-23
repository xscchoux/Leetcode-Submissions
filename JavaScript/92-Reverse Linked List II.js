/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} m
 * @param {number} n
 * @return {ListNode}
 */
var reverseBetween = function(head, m, n) {
    
    // prev -> start -> ...  -> tail
    
    
    const dummy = new ListNode(0);
    dummy.next = head;
    let prev = dummy;
    
    for (let i=0; i<m-1; i++){
        prev = prev.next;
    }

    let start = prev.next;
    let tail = start
    
    for (let i=0; i<n-m; i++){
        tail = tail.next;
    }

    tail = tail.next;
    
    for (let i=0; i<n-m+1; i++){
        let tmp = start.next;
        start.next = tail;
        tail = start;
        start = tmp;
    }
    
    prev.next = tail;
    
    return dummy.next;
};