/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {number} n
 * @return {TreeNode[]}
 */
var generateTrees = function(n) {
    
        let memo = new Map();
    
        let dfs = (start, end) =>{
            if (end < start) return [null];
            if (start === end) return [new TreeNode(start)];
            if (memo.has(`${start}-${end}`)) return memo.get(`${start}-${end}`);
            let subTree = new Array();
            for (let i=start; i<=end; i++){
                for (let leftSubTree of dfs(start, i-1)){
                    for (let rightSubTree of dfs(i+1, end)){
                        let currNode = new TreeNode(i);
                        currNode.left = leftSubTree;
                        currNode.right = rightSubTree;
                        subTree.push(currNode);
                    }
                }
            }
            memo.set(`${start}-${end}`, subTree);
            return subTree;
        }
        return dfs(1, n);
};