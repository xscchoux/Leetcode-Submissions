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
var longestConsecutive = function(root) {
    res = 0;
    
    let dfs = (node) =>{
        if (!node) return 0;
        
        let length = 1
        
        if (node.left){
            if (node.val + 1 === node.left.val){
                length = dfs(node.left) + 1;
            }else{
                dfs(node.left);
            }
        }
        
        if (node.right){
            if (node.val + 1 === node.right.val){
                length = Math.max(length, dfs(node.right)+1);
            }else{
                dfs(node.right);
            }
        }
        
        res = Math.max(res, length);
        return length;
    }
    dfs(root);
    return res;
};