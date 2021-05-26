/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @param {TreeNode[]} nodes
 * @return {TreeNode}
 */
var lowestCommonAncestor = function(root, nodes) {
    let nodeSet = new Set(nodes);
    
    let dfs = (node) =>{
        if (!node || nodeSet.has(node)){
            return node;
        }
        let left = dfs(node.left);
        let right = dfs(node.right);
        
        if (left && right){
            return node;
        }else{
            return left || right;
        }
        
    }
    return dfs(root);
};