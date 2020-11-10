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
var maxAncestorDiff = function(root) {
    maxValue = Number.NEGATIVE_INFINITY;
    minValue = Number.POSITIVE_INFINITY;
    res = 0
    let dfs = (root) => {
        if (!root){
            return [maxValue, minValue];
        }
        let [leftMax, leftMin] = dfs(root.left);
        let [rightMax, rightMin] = dfs(root.right);

        let currMax = Math.max(root.val,leftMax, rightMax);
        let currMin = Math.min(root.val, leftMin, rightMin);     
        res = Math.max(res, Math.abs(root.val-currMax), Math.abs(root.val-currMin));
        return [currMax, currMin];
    }
    dfs(root);
    return res;
};