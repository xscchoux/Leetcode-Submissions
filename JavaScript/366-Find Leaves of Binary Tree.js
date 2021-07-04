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
 * @return {number[][]}
 */
var findLeaves = function(root) {
    let res = new Array();
    
    let dfs = (node) =>{
        if (!node) return -1;
        let leftH = dfs(node.left);
        let rightH = dfs(node.right);
        let h = Math.max(leftH, rightH) + 1;
        if (h === res.length){
            res.push(new Array());
        }
        res[h].push(node.val);
        return h;
    }
    dfs(root);
    return res;
};