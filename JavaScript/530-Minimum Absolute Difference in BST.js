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
var getMinimumDifference = function(root) {
    
    let dfs = (node, min, max) =>{
        if (!node) return max-min;
        let left = dfs(node.left, min, node.val);
        let right = dfs(node.right, node.val, max);
        return Math.min(left, right);
    }
    return dfs(root, Number.NEGATIVE_INFINITY, Number.POSITIVE_INFINITY)
    
};