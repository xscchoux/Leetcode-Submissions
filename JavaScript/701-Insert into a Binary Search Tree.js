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
 * @param {number} val
 * @return {TreeNode}
 */
var insertIntoBST = function(root, val) {
    
    let helper = (root) =>{
        if (!root) return new TreeNode(val);
        
        if (val > root.val){
            root.right = helper(root.right);
        } 
        else{
            root.left = helper(root.left);
        }
        return root;
    }
    return helper(root);
};