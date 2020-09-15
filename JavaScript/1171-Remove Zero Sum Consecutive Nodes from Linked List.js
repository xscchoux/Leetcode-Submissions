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
var removeZeroSumSublists = function(head) {
    const dummy = new ListNode(0);
    dummy.next = head;
    const hmap = new Map()
    pSum = 0;
    hmap.set(pSum, dummy)
    
    while (head){
        pSum += head.val;
        if(hmap.has(pSum)){
            let tmp = pSum, start = hmap.get(pSum).next;
            while (start !== head){
                tmp += start.val;
                hmap.delete(tmp);
                start = start.next;
            }
            hmap.get(pSum).next = head.next;
        } else{
            hmap.set(pSum, head);
        }
        head = head.next;
    }
    return dummy.next;
};