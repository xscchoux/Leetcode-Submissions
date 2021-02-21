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
 * @param {number} v
 * @param {number} d
 * @return {TreeNode}
 */
var addOneRow = function(root, v, d) {
    if (d === 1){
        tmp = new TreeNode(v);
        tmp.left = root;
        return tmp;
    }
    
    let dfs = (node, depth) =>{
        if (!node){
            return null;
        }
        if (depth === 2){
            let nextLeft = node.left, nextRight = node.right;
            node.left = new TreeNode(v);
            node.right = new TreeNode(v);
            node.left.left = nextLeft;
            node.right.right = nextRight;
        } else{
            dfs(node.left, depth-1);
            dfs(node.right, depth-1);
        }
        return node;
    }
    dfs(root,d);
    return root;
};