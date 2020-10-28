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
var verticalOrder = function(root) {
    if (!root) return [];
    let queue = [[root, 0]];
    let res = new Map();
    let minCol = 0, maxCol = 0;
    while (queue.length){
        queueSize = queue.length;
        for (let i=0; i<queueSize; i++){
            let [node, pos] = queue.shift();
            res.set(pos, (res.get(pos)|| []).concat([node.val]) )
            if (node.left){
                queue.push([node.left, pos-1]);
                minCol = Math.min(minCol, pos-1);
            }
            if (node.right){
                queue.push([node.right, pos+1]);
                maxCol = Math.max(maxCol, pos+1);
            }
        }
    }
    let ans = [];
    for (let i=minCol; i<=maxCol; i++){
        if (res.has(i)){
            ans.push(res.get(i));
        }
    }
    return ans;
};