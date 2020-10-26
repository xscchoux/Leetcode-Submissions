/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @param {TreeNode} p
 * @return {TreeNode}
 */
var inorderSuccessor = function(root, p) {
    let prev = null;
    stack = [];
    while (true){
        if (root !== null){
            stack.push(root);
            root = root.left;
        } else if (stack.length > 0){
            root = stack.pop();
            if (prev === p){
                return root;
            }
            prev = root;
            root = root.right;
        } else{
            break;
        }
    }
    return null;
};