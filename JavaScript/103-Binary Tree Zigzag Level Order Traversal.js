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
 * @return {number[][]}
 */
var zigzagLevelOrder = function(root) {
    if (!root) return new Array();
    let reverse = false;
    let queue = new Array(1).fill(root);
    let res = new Array();
    while (queue.length){
        let nxt = [];
        const size = queue.length;
        console.log(size)
        for (let i=0; i<size; i++){
            let curr = queue.shift();
            if (reverse){
                nxt.unshift(curr.val);
            }else{
                nxt.push(curr.val);
            }
            
            if (curr.left) queue.push(curr.left);
            if (curr.right) queue.push(curr.right);
        }
        res.push(nxt);
        reverse = !reverse;
    }
    return res;
};