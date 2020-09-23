/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */

/**
 * @param {ListNode} headA
 * @param {ListNode} headB
 * @return {ListNode}
 */

// use set
var getIntersectionNode = function(headA, headB) {
    let visited = new Set();
    while (headA){
        visited.add(headA);
        headA = headA.next;
    }
    
    while (headB){
        if (visited.has(headB)){
            return headB;
        }
        headB = headB.next;
    }
    
    return null;
};


// without extra space
var getIntersectionNode = function(headA, headB) {
    let pA = headA, pB = headB;
    while (pA != pB){
        if (pA === null) pA = headB;
        else pA = pA.next;
        
        if (pB === null) pB = headA;
        else pB = pB.next;
    }
    
    return pA;
};
