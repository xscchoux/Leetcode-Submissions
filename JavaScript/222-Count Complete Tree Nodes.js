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
var countNodes = function(root) {
    
    let leftDepth = (node) =>{
        if (!node) return 0;
        return 1 + leftDepth(node.left);
    }
    
    let dfs = (node) =>{
        if (!node) return 0;
        
        let h1 = leftDepth(node.left), h2 = leftDepth(node.right);
        let res = 1;
        if (h1 !== h2){
            res += Math.pow(2, h2) - 1 + dfs(node.left);
        }else{
            res += Math.pow(2, h1) - 1 + dfs(node.right);
        }
        return res
    }
    
    return dfs(root);
};