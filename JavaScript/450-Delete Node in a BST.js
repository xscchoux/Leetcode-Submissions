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
 * @param {number} key
 * @return {TreeNode}
 */
var deleteNode = function(root, key) {
    
    let dfs = (node, key) =>{
        if (!node) return null;
        if (key > node.val){
            node.right = dfs(node.right, key);
        }else if(key < node.val){
            node.left = dfs(node.left, key);
        }else{
            if (!node.left || !node.right){
                node = (node.left || node.right);
            }else{
                let _min = node.right;
                while (_min.left){
                    _min = _min.left;
                }
                _min.left = node.left;
                node = node.right;
            }
        }
        return node;
    }
    return dfs(root, key);
};