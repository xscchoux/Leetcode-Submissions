/**
 * // Definition for a Node.
 * function Node(val,prev,next,child) {
 *    this.val = val;
 *    this.prev = prev;
 *    this.next = next;
 *    this.child = child;
 * };
 */

/**
 * @param {Node} head
 * @return {Node}
 */
var flatten = function(head) {
    if (!head) return null;
        
    let stack = [head];
    let dummyHead = new Node(0, null, head, null);
    let prevHead = dummyHead;
    
    while (stack.length){
        let currHead = stack.pop();
        currHead.prev = prevHead;
        prevHead.next = currHead;
        
        if (currHead.next){
            stack.push(currHead.next);
        }
        if (currHead.child){
            stack.push(currHead.child);
            currHead.child = null;
        }
        prevHead = currHead;
    }
    dummyHead.next.prev = null;
    return dummyHead.next;
};