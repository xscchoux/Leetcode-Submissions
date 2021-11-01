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
 * @param {number[]} to_delete
 * @return {TreeNode[]}
 */
var delNodes = function(root, to_delete) {
    
    const deleteSet = new Set(to_delete);
    let res = [];
    
    let dfs = (node, parentExist) =>{
        if (!node) return null;
        const exist = !deleteSet.has(node.val);
        if (exist && !parentExist){
            res.push(node);
        }
        node.left = dfs(node.left, exist);
        node.right = dfs(node.right, exist);
        
        return exist? node: null;
        
    }
    dfs(root, false);
    
    return res;
};