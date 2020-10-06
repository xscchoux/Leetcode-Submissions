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
 * @param {number} target
 * @param {number} k
 * @return {number[]}
 */
var closestKValues = function(root, target, k) {
    let res = [], stack = [];
    while (true){
        if (root){
            stack.push(root);
            root = root.left;
        }
        else if (stack.length > 0){
            root = stack.pop();
            if (res.length < k){
                res.push(root.val);
            }
            else{
                if (Math.abs(target-res[0]) > Math.abs(root.val - target)){
                    res.push(root.val);
                    res.shift();
                }
            }
            root = root.right;
        }
        else{
            break;
        }
    }
    return res
};