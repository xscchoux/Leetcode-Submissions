/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number}
 */
var minDepth = function(root) {
    if (!root) return 0;
    
    let queue = [root];
    let depth = 0
    while (queue.length){
        depth += 1
        let size = queue.length;
        for (let i=0; i<size; i++){
            let curr = queue.shift();
            if (!curr.left && !curr.right){
                return depth;
            }
            if (curr.left){
                queue.push(curr.left);
            }
            if (curr.right){
                queue.push(curr.right);
            }
        }
    }
};