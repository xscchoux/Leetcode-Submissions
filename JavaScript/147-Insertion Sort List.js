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
var insertionSortList = function(head) {
    if (!head) return null;
    let dummy = new ListNode(Number.NEGATIVE_INFINITY);
    dummy.next = head;
    let curr = dummy;
    
    while (curr.next){
        if (curr.next.val >= curr.val){
            curr = curr.next;
        }else{
            let tmp = curr.next;
            curr.next = curr.next.next;
            let prev = dummy;
            while (prev.next.val < tmp.val){
                prev = prev.next;
            }
            tmp.next = prev.next;
            prev.next = tmp;
        }
    }
    return dummy.next;
};