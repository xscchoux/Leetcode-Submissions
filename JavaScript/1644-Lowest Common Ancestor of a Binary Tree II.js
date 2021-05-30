/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @param {TreeNode} p
 * @param {TreeNode} q
 * @return {TreeNode}
 */
var lowestCommonAncestor = function(root, p, q) {
    
// Method 1
    let res = null;
    let dfs = (node) =>{
        if (!node) return 0;
        let curr = (node === p || node === q);
        let left = dfs(node.left);
        let right = dfs(node.right);
        if (left + right + curr === 2 && res === null){
            res = node;
        }
        return left + right + curr;
    }
    dfs(root);
    
    return res;
    
// Method 2    
    let count = 0;
    
    let dfs = (node) =>{
        if (!node) return null;
        let left = dfs(node.left), right = dfs(node.right);
        if (node === p){
            count += 1;
            return node;
        }
        if (node === q){
            count += 1;
            return node;
        }
        if (left && right){
            return node;
        }else{
            return left || right;
        }
    }
    
    let res = dfs(root);
    return (count === 2)? res:null;
};