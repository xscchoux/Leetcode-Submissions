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
    let res = null;
    let dfs = (node) =>{
        if (!node) return 0;
        
        let curr = (node === p || node === q);
        let left = dfs(node.left);
        let right = dfs(node.right);
        // console.log(curr+left+right)
        if (curr + left + right === 2 && res === null){
            res = node;
        }
        return curr + left + right;
    }
    dfs(root);
    return res;
};