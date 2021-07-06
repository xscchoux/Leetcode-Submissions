/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {number[]} inorder
 * @param {number[]} postorder
 * @return {TreeNode}
 */
var buildTree = function(inorder, postorder) {
    const N = inorder.length;
    let hmap = new Map();
    for (let i=0; i<inorder.length; i++){
        hmap.set(inorder[i], i);
    }
    
    let dfs = (start1, end1, start2, end2) =>{
        if (end1 < start1) return null;
        let root = new TreeNode(postorder[end1]);
        rootIndex = hmap.get(postorder[end1]);
        
        let rightLen = end2 - rootIndex;
        
        root.left = dfs(start1, end1-rightLen-1, start2, rootIndex-1);
        root.right = dfs(end1-rightLen, end1-1, rootIndex+1, end2);
        
        return root;
    }
    
    return dfs(0, N-1, 0, N-1);
};