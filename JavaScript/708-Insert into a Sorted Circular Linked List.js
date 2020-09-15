/**
 * // Definition for a Node.
 * function Node(val, next) {
 *     this.val = val;
 *     this.next = next;
 * };
 */

/**
 * @param {Node} head
 * @param {number} insertVal
 * @return {Node}
 */
var insert = function(head, insertVal) {
    if (!head){
        newHead = new Node(insertVal, null);
        newHead.next = newHead;
        return newHead;
    }
    
    start = head
    
    while (true){
        if (head.val > head.next.val){
            if(insertVal > head.val || insertVal < head.next.val){
                break;
            }
        } else if (head.val <= insertVal && insertVal <= head.next.val){
            break;
        } 
        else if (head.next === start){
            break
        }
        head = head.next;
    }
    
    const tmp = head.next;
    const newNode = new Node(insertVal, null);
    head.next = newNode;
    newNode.next = tmp
    
    return start
};