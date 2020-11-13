/**
 * // Definition for a Node.
 * function Node(val, left, right, next) {
 *    this.val = val === undefined ? null : val;
 *    this.left = left === undefined ? null : left;
 *    this.right = right === undefined ? null : right;
 *    this.next = next === undefined ? null : next;
 * };
 */

/**
 * @param {Node} root
 * @return {Node}
 */
var connect = function(root) {
    if (!root) return null;
    let queue = [root];
    
    while (queue.length){
        const size = queue.length;
        for (let i=0; i<size; i++){
            const curr = queue.shift();
            if (i<size-1){
                curr.next = queue[0];
            }
            if (curr.left){
                queue.push(curr.left);
            }
            if (curr.right){
                queue.push(curr.right);
            }
        }
    }
    return root;
};