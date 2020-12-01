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
var deepestLeavesSum = function(root) {
    let listNode = [root];
    
    let findLeaves = (list) =>{
        let currList = [];
        for (let node of list){
            if (node.left){
                currList.push(node.left);
            }
            if (node.right){
                currList.push(node.right);
            }
        }
        if (!currList.length){
            return list.reduce(function(arr, x){
               return arr + x.val; 
            },0)
        }
        return findLeaves(currList);
    }
    
    return findLeaves(listNode);
};