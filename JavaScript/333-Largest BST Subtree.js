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
var largestBSTSubtree = function(root) {
    let res = 0;
    let dfs = (node) =>{
        if (!node) return [Number.MAX_SAFE_INTEGER, Number.MIN_SAFE_INTEGER, 0];
        
        const [leftMin, leftMax, leftNum] = dfs(node.left);
        const [rightMin, rightMax, rightNum] = dfs(node.right);
        
        if (leftMax < node.val && node.val < rightMin && leftNum >=0 && rightNum >= 0){
            res = Math.max(leftNum + rightNum + 1, res);
            return [Math.min(node.val, leftMin), Math.max(node.val, rightMax), leftNum + rightNum + 1];
        }
        
        return [Number.MAX_SAFE_INTEGER, Number.MIN_SAFE_INTEGER, -1];
    }
    
    dfs(root);
    return res;
};