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
//Sol 1
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
    
// Sol 2
    let covered = new Set();
    covered.add(null);
    
    let dfs = (node, parent) =>{
        if (!node) return 0;
        let result = dfs(node.left, node) + dfs(node.right, node);
        if (!covered.has(node.left) || !covered.has(node.right)){
            covered.add(node.left);covered.add(node.right);covered.add(node);covered.add(parent);
            result += 1;
        }
        return result;
    }
    res = dfs(root, null);
    
    return covered.has(root)?res:res+1;
};