/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {void} Do not return anything, modify head in-place instead.
 */
var reorderList = function(head) {
    if (!head) return null;
    let slow = head, fast = head;
    while (fast && fast.next){
        slow = slow.next;
        fast = fast.next.next;
    }
    let nxt = slow.next;
    slow.next = null;
    let prev = null;
    
    while (nxt){
        let tmp = nxt.next;
        nxt.next = prev;
        prev = nxt;
        nxt = tmp;
    }
    
    let curr = new ListNode(0)
    
    while (head){
        curr.next = head;
        curr = curr.next;
        head = head.next;
        if (prev){
            curr.next = prev;
            curr = curr.next;
            prev = prev.next;
        }
    }
};