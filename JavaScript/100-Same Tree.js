/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} p
 * @param {TreeNode} q
 * @return {boolean}
 */
var isSameTree = function(p, q) {
    let dfs = (p, q) =>{
        if (!p && !q) return true;
        if (!p || !q) return false;
        if (p.val !== q.val) return false;
        return dfs(p.left, q.left) && dfs(p.right, q.right);
    }
    return dfs(p,q);
};