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
 * @return {void} Do not return anything, modify root in-place instead.
 */
var recoverTree = function(root) {
    let first = null, second = null;
    prev = new TreeNode(Number.NEGATIVE_INFINITY);
    stack = [];
    
    while (true){
        if (root){
            stack.push(root);
            root = root.left;
        } else if (stack.length > 0){
            root = stack.pop();
            if (prev.val !== Number.NEGATIVE_INFINITY && root.val <= prev.val){
                if (first === null) first = prev;
                if (first !== null) second = root;
            }
            prev = root;
            root = root.right;
        } else{
            break;
        }
    }
    [first.val, second.val] = [second.val, first.val];
};