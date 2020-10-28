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
 * @return {TreeNode}
 */
var balanceBST = function(root) {
    let nodeList = [];
    
    let traverseAdd = (node)=> {
        if (!node) return;
        traverseAdd(node.left);
        nodeList.push(node.val);
        traverseAdd(node.right);
    }
    traverseAdd(root);
    
    let construct = (left, right) =>{
        if (right < left) return null;
        let mid = left + Math.floor((right-left)/2);
        let currNode = new TreeNode(nodeList[mid]);
        currNode.left = construct(left, mid-1);
        currNode.right = construct(mid+1, right);
        return currNode
    }
    
    return construct(0, nodeList.length-1);
};