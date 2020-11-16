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
 * @param {number} low
 * @param {number} high
 * @return {number}
 */
var rangeSumBST = function(root, low, high) {
    res = 0
    
    let dfs = (root) => {
        if (!root) return;
        if (low <= root.val && root.val <= high){
            res += root.val;
        }
        if (root.val > low){
            dfs(root.left);
        }
        if (root.val < high){
            dfs(root.right);
        }
    }
    dfs(root);
    return res;
};