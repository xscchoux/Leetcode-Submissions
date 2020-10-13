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
    let ans = root;
    let LCA = (root) =>{
        if (!root) return 0;
        
        let left = LCA(root.left);
        let right = LCA(root.right);
        
        let mid = 0;
        if (root === p || root === q){
            mid = 1;
        }
        if (mid + left + right === 2) ans = root;
        return mid || left || right;
    }
    
    LCA(root);
    return ans;
};