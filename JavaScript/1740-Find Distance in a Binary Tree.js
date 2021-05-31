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
 * @param {number} p
 * @param {number} q
 * @return {number}
 */
var findDistance = function(root, p, q) {
// find LCA, then BFS
    let LCA = (node) =>{
        if (!node) return null;
        if (node.val === p || node.val === q) return node;
        let left = LCA(node.left), right = LCA(node.right);
        if (left && right){
            return node;
        }else{
            return (left || right);
        }
    }
    
    let LCAnode = LCA(root);
    
    let findDist = (ancestor, value) =>{
        let queue = [[ancestor, 0]];
        while (queue.length){
            size = queue.length;
            for (let i=0; i<size; i++){
                let [curr, step] = queue.shift();
                if (curr.val === value){
                    return step;
                }
                if (curr.left){
                    queue.push([curr.left, step+1]);
                }
                if (curr.right){
                    queue.push([curr.right, step+1]);
                }
            }
        }
    }
    
    return findDist(LCAnode, p) + findDist(LCAnode, q);
};