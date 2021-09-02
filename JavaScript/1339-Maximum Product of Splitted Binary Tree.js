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
var maxProduct = function(root) {
    let sumArr = new Set();
    const kMod = 1000000007;
    let res = 0;
    
    let dfs = (node) =>{
        if (!node) return 0;
        let left = dfs(node.left), right = dfs(node.right);
        sumArr.add(node.val+left+right);
        return node.val+left+right;
    }
    let total = dfs(root);
    for (let num of sumArr){
        res = Math.max(res, (total-num)*num );
    }
    return res%kMod;
};