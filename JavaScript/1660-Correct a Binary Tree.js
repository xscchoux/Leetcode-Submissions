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
 * @param {number} from
 * @param {number} to
 * @return {TreeNode}
 */
var correctBinaryTree = function(root) {
    let queue = [root];
    let seen = new Set([root.val]);
    
    while (queue.length){
        let curr = queue.shift();
        if (curr.right){
            let grandRightNode = curr.right.right;
            if (grandRightNode && seen.has(grandRightNode.val) ){
                curr.right = null;
                return root;
            }
            seen.add(curr.right.val);
            queue.push(curr.right);
        }
        if (curr.left){
            let grandLeftNode = curr.left.right;
            if (curr.left.right && seen.has(grandLeftNode.val) ){
                curr.left = null;
                return root;
            }
            seen.add(curr.left.val);
            queue.push(curr.left);
        }
    }
};