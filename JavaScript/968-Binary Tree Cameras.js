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
 * @return {number}
 */

// 0: leaf node or node not covered
// 1: with camera, covered
// 2: without camera, covered

var minCameraCover = function(root) {
    let res = 0;
    let helper = (node) =>{
        if (!node) return 2;
        let left = helper(node.left), right = helper(node.right);
        if (left === 0 || right === 0){
            res += 1;
            return 1;
        }else if ( left === 1 || right === 1){
            return 2;
        }else{
            return 0;
        }
    }
    return (helper(root) === 0)?res+1:res; 
};