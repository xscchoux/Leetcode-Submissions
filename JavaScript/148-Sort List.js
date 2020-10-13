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
var sortList = function(head) {
    if (head === null || head.next === null) return head;
    let slow = head, fast = head, prev = new ListNode(0);
    prev.next = head;
    while (fast && fast.next){
        prev = prev.next;
        slow = slow.next;
        fast = fast.next.next;
    }
    prev.next = null
    let one = sortList(head);
    let two = sortList(slow);   
    return merge(one, two)
};

var merge = function(one, two){
    let dummy = new ListNode(0)
    let curr = dummy
    while (one !==null && two!==null){
        if (one.val <= two.val){
            curr.next = one;
            one = one.next;
        } else{
            curr.next = two;
            two = two.next;
        }
        curr = curr.next;
    }
    curr.next = one || two;
    return dummy.next
}