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
var longestUnivaluePath = function(root) {
    let res = 0;
    
    let dfs = (node) => {
        if (!node){
            return 0;
        }
        
        let prevLeft = dfs(node.left);
        let prevRight = dfs(node.right);
        let leftLength = 0, rightLength = 0;
        
        if (node.left && node.left.val === node.val){
            leftLength = 1 + prevLeft;
        }
        if (node.right && node.right.val === node.val){
            rightLength = 1 + prevRight;
        }
        res = Math.max(res, leftLength + rightLength);
        
        return Math.max(leftLength, rightLength);
    }
    dfs(root);
    
    return res;
};