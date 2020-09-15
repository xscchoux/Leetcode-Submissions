/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var swapPairs = function(head) {
    if (!head) return null;
    
    let dummy = new ListNode(0, head);
    let dum = dummy;
    let tmp = null;
    
    while (head && head.next){
        tmp = head.next;
        head.next = head.next.next;
        dum.next = tmp;
        tmp.next = head;
        dum = head;
        head = head.next;
    }
    
    return dummy.next;
    
};