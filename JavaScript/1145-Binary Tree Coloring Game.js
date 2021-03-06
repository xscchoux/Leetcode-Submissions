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
 * @param {number} n
 * @param {number} x
 * @return {boolean}
 */
var btreeGameWinningMove = function(root, n, x) {
    let leftSide = 0, rightSide = 0;
    
    let dfs = (node) =>{
        if (!node) return 0;
        
        if (node.val === x){
            leftSide = dfs(node.left);
            rightSide = dfs(node.right);
            return 0;
        }
        
        return 1 + dfs(node.left) + dfs(node.right);
    }
    
    dfs(root);
    
    return Math.max( Math.max(leftSide, rightSide), n-leftSide-rightSide-1 ) > n/2;
};