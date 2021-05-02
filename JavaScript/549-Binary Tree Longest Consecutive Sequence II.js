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
    let res = 0;
    
    let dfs = (node) =>{
        
        let inc = 0, dec = 0;
        
        if (node.left){
            let [dec1, inc1] = dfs(node.left);
            if (node.val + 1 === node.left.val){
                dec = dec1;
            }else if (node.val - 1 === node.left.val){
                inc = inc1;
            }
        }
        
        if (node.right){
            let [dec2, inc2] = dfs(node.right);
            if (node.val + 1 === node.right.val){
                dec = Math.max(dec, dec2);
            }else if (node.val - 1 === node.right.val){
                inc = Math.max(inc, inc2);
            }
        }
        res = Math.max(res, inc + 1 + dec);
        return [dec+1, inc+1];
    }
    dfs(root);
    return res;
};