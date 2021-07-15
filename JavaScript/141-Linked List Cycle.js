/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */

/**
 * @param {ListNode} head
 * @return {boolean}
 */
var hasCycle = function(head) {
// sol1
    let visited = new Set();
    while (head){
        if (visited.has(head)) return true;
        visited.add(head);
        head = head.next;
    }
    return false;
    
// sol2
    if (!head) return false;
    let [slow, fast] = [head, head.next];
    while (fast && fast.next){
        if (slow === fast) return true;
        slow = slow.next;
        fast = fast.next.next;
    }
    return false;
};