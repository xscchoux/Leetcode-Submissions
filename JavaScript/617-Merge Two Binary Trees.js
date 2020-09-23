/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} t1
 * @param {TreeNode} t2
 * @return {TreeNode}
 */
var mergeTrees = function(t1, t2) {
    let dfs = (t1, t2) =>{
        if (!t1) return t2;
        else if (!t2) return t1;
        else{
            t1.val += t2.val;
            t1.left = dfs(t1.left, t2.left);
            t1.right = dfs(t1.right, t2.right);
            return t1;
        }
    }
    return dfs(t1, t2);
};