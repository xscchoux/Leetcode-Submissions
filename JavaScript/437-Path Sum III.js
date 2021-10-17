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
 * @param {number} targetSum
 * @return {number}
 */
var pathSum = function(root, targetSum) {
    let hmap =  new Map();
    hmap.set(0, 1);
    let res = 0;
    let dfs = (node, currSum) =>{
        if (!node) return;
        
        currSum += node.val;
        res += (hmap.get(currSum-targetSum)|| 0);
        hmap.set(currSum, (hmap.get(currSum)||0) + 1);      
        dfs(node.left, currSum);
        dfs(node.right, currSum);
        hmap.set(currSum, hmap.get(currSum) - 1);
    }
    dfs(root, 0);
    return res;
};