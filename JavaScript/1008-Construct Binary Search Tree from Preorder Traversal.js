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
 * @return {TreeNode}
 */
var bstFromPreorder = function(preorder) {  
    let dfs = (start, end) =>{
        if (start > end) return null;
        
        let root = new TreeNode(preorder[start]);
        let rightIdx = end+1;
        for (let i=start; i<=end; i++){
            if (preorder[i] > preorder[start]){
                rightIdx = i;
                break;
            }
        }
        
        root.left = dfs(start+1, rightIdx-1);
        root.right = dfs(rightIdx, end);
        return root;
    }
    
    return dfs(0, preorder.length-1);
};