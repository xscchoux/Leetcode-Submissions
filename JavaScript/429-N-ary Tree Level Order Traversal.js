/**
 * // Definition for a Node.
 * function Node(val,children) {
 *    this.val = val;
 *    this.children = children;
 * };
 */

/**
 * @param {Node} root
 * @return {number[][]}
 */
var levelOrder = function(root) {
    if (!root) return [];
    
    let res = [], queue = [root];
    
    while (queue.length){
        let level = [], queueL = queue.length;
        for (let i=0; i< queueL; i++){
            let curr = queue.shift();
            level.push(curr.val);
            for (let nxt of curr.children){
                queue.push(nxt);
            }
        }
        res.push(level);
    }
    return res;
};