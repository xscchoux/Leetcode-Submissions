/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {number[]} preorder
 * @param {number[]} inorder
 * @return {TreeNode}
 */
var buildTree = function(preorder, inorder) {
    const N = preorder.length;
    let hmap = new Map();
    for (let i=0; i<inorder.length; i++){
        hmap.set(inorder[i], i);
    }
    
    let dfs = (start1, end1, start2, end2)=>{
        if (end1 < start1) return null;
        
        let root = new TreeNode(preorder[start1]);
        let rootIndex = hmap.get(preorder[start1]);
        
        let leftLen = rootIndex - start2, rightLen = end2 - rootIndex;
        
        root.left = dfs(start1+1, start1+leftLen, start2, rootIndex-1);
        root.right = dfs(start1 + leftLen+1, end1, rootIndex+1, end2);
        
        return root;
    }
    
    return dfs(0, N-1, 0, N-1);
};