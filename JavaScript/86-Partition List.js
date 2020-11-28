/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} x
 * @return {ListNode}
 */
var partition = function(head, x) {
    
    let head1 = new ListNode(0);
    let head1Curr = head1;
    let head2 = new ListNode(0);
    let head2Curr = head2;
    
    while (head){
        if (head.val < x){
            head1Curr.next = head;
            head1Curr = head1Curr.next;
        }else{
            head2Curr.next = head;
            head2Curr = head2Curr.next;
        }
        head = head.next;
    }
    
    head2Curr.next = null;
    head1Curr.next = head2.next;
    
    return head1.next;
};