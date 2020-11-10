/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {number} N
 * @return {TreeNode[]}
 */

var allPossibleFBT = function(N) {
    if (N % 2 === 0) return [];
    let memo = new Map();
    
    memo.set(1, [new TreeNode(0)])
    
    let dfs = (N) =>{
        if (memo.has(N)){
            return memo.get(N);
        }
        
        let trees = [];
        for (let leftNum = 1; leftNum <= N-2; leftNum += 2){
            let rightNum = N - leftNum - 1;
            for (let leftTree of dfs(leftNum)){
                for (let rightTree of dfs(rightNum)){
                    let root = new TreeNode(0);
                    root.left = leftTree;
                    root.right = rightTree;
                    trees.push(root);
                }
            }
        }
        memo.set(N, trees)
        return trees;
    }
    return dfs(N);
};