/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var addTwoNumbers = function(l1, l2) {
    let dummy = new ListNode(0);
    let curr = dummy, carry = 0;
    
    while (l1 || l2 || carry){
        if (l1){
            carry += l1.val;
            l1 = l1.next;
        }
        if (l2){
            carry += l2.val;
            l2 = l2.next;
        }
        let remainder = carry % 10;
        carry = Math.floor(carry/10);
        curr.next = new ListNode(remainder)
        curr = curr.next;
    }
    return dummy.next;
};