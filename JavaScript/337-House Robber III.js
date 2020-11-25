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
var rob = function(root) {
    let dfs = (root) =>{
        if (!root){
            return [0, 0];
        }
        
        let [leftWith, leftWithout] = dfs(root.left);
        let [rightWith, rightWithout] = dfs(root.right);
        
        return [root.val + leftWithout + rightWithout, Math.max(leftWith, leftWithout) + Math.max(rightWith, rightWithout)];
    }
    
    return Math.max(...dfs(root));
};