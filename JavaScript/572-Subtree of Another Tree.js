/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} s
 * @param {TreeNode} t
 * @return {boolean}
 */
var isSubtree = function(s, t) {
    let construct = (root) =>{
        if (!root) return '#';
        let string = root.val.toString() + ',' + construct(root.left) +',' + construct(root.right);
        return string
    }
    
    let tString = construct(t);
    let bool = false;
    
    let dfs = (root) => {
        if (!root) return '#';
        let string = root.val.toString() + ',' + dfs(root.left) + ',' + dfs(root.right);
        if (string === tString) bool = true;
        return string;
    }
    
    dfs(s);
    return bool;
};