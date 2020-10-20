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
 * @return {TreeNode[]}
 */
var findDuplicateSubtrees = function(root) {
    let hmap = new Map();
    let res = [];
    
    let dfs = (root) =>{
        if (!root) return '#';
        let serial = root.val.toString() + "," + dfs(root.left) + "," + dfs(root.right);
        hmap.set(serial, (hmap.get(serial)||0) + 1);
        if (hmap.get(serial) === 2){
            res.push(root);
        }
        return serial;
    }
    dfs(root);
    return res;
};