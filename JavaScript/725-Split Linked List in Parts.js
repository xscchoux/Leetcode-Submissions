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
 * @return {ListNode[]}
 */
var splitListToParts = function(head, k) {
    let tmp = head, N = 0;
    
    while (tmp){
        tmp = tmp.next;
        N += 1;
    }
    
    let res = new Array();
    let runningHead = head;
    const first = N%k;
    const num = Math.floor(N/k);

    for (let i=0; i<k; i++){
        if (!runningHead){
            for (let x = i; x<k; x++){
                res.push(null);
            }
            return res;
        }
        res.push(runningHead);
        for (let j=0; j<num-1+(i<first); j++){
            runningHead = runningHead.next;
        }
        let prev = runningHead;
        runningHead = runningHead.next;
        prev.next = null;
    }
    
    return res;
};