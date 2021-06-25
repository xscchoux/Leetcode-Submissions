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

// Recursive
let leftHead, stop;
var reverseBetween = function(head, left, right) {
    leftHead = head
    stop = false;
    let rightHead = head;

    let dfs = (rightHead, left, right) =>{
        if (right === 1) return;
        rightHead = rightHead.next;
        if (left > 1){
            leftHead = leftHead.next
        }
        
        dfs(rightHead, left-1, right-1)
        
        if (stop) return;
        
        if (rightHead.next === leftHead || leftHead === rightHead){
            stop = true;
            return;
        }
        [leftHead.val, rightHead.val] = [rightHead.val, leftHead.val];
        leftHead = leftHead.next;   
    }
    dfs(rightHead, left, right);
    return head;
};


//Iterative
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