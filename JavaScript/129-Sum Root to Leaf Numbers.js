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
var sumNumbers = function(root) {
    let res = 0
    let dfs = (node, prev) =>{
        if (!node) return;
        let curr = 10*prev + node.val;
        if (!node.left && !node.right){
            res += curr;
            return;
        }
        dfs(node.left, curr);
        dfs(node.right, curr);
    }
    dfs(root, 0);
    return res;
};