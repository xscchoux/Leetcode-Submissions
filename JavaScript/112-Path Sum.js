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
 * @param {number} targetSum
 * @return {boolean}
 */
var hasPathSum = function(root, targetSum) {
    let dfs = (node, prevSum) =>{
        if (!node) return false;
        
        if (node.val + prevSum === targetSum && !node.left && !node.right){
            return true;
        }
        
        return dfs(node.left, node.val + prevSum) || dfs(node.right, node.val + prevSum);
    }
    
    return dfs(root, 0);
};